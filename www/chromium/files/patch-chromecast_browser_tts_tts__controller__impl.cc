--- chromecast/browser/tts/tts_controller_impl.cc.orig	2019-01-31 23:07:11.992155000 +0100
+++ chromecast/browser/tts/tts_controller_impl.cc	2019-01-31 23:08:40.991798000 +0100
@@ -390,7 +390,11 @@
 }
 
 TtsPlatformImpl* TtsControllerImpl::GetPlatformImpl() {
+#if defined(OS_BSD)
+  return NULL;
+#else
   return platform_impl_.get();
+#endif // defined(OS_BSD)
 }
 
 std::string TtsControllerImpl::GetApplicationLocale() const {
