#include <jni.h>
#include <string>
#include "opus/opus.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_live_calendar_youloft_com_opus_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    int error;
    OpusDecoder *decoder = opus_decoder_create(8000, 2, &error);
    if (decoder != NULL) {
        return env->NewStringUTF("Success");
    }
    return env->NewStringUTF(opus_get_version_string());
}
