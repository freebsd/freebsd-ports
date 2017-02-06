--- chrome/browser/speech/tts_controller_impl.cc.orig	2017-01-26 00:49:09 UTC
+++ chrome/browser/speech/tts_controller_impl.cc
@@ -347,9 +347,13 @@ int TtsControllerImpl::QueueSize() {
 }
 
 TtsPlatformImpl* TtsControllerImpl::GetPlatformImpl() {
+#if defined(OS_BSD)
+  return NULL;
+#else
   if (!platform_impl_)
     platform_impl_ = TtsPlatformImpl::GetInstance();
   return platform_impl_;
+#endif
 }
 
 int TtsControllerImpl::GetMatchingVoice(
