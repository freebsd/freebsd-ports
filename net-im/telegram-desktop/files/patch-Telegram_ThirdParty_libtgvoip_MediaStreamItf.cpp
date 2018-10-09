--- Telegram/ThirdParty/libtgvoip/MediaStreamItf.cpp.orig	2018-09-18 16:52:01 UTC
+++ Telegram/ThirdParty/libtgvoip/MediaStreamItf.cpp
@@ -22,7 +22,7 @@ void MediaStreamItf::SetCallback(size_t 
 size_t MediaStreamItf::InvokeCallback(unsigned char *data, size_t length){
 	if(callback)
 		return (*callback)(data, length, callbackParam);
-	return NULL;
+	return 0;
 }
 
 AudioMixer::AudioMixer() : bufferPool(960*2, 16), processedQueue(16), semaphore(16, 0){
