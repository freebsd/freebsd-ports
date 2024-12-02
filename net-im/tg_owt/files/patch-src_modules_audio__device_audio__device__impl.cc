--- src/modules/audio_device/audio_device_impl.cc.orig	2024-12-02 05:33:43 UTC
+++ src/modules/audio_device/audio_device_impl.cc
@@ -141,7 +141,7 @@ int32_t AudioDeviceModuleImpl::CheckPlatform() {
 #elif defined(WEBRTC_ANDROID)
   platform = kPlatformAndroid;
   RTC_LOG(LS_INFO) << "current platform is Android";
-#elif defined(WEBRTC_LINUX)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_FREEBSD)
   platform = kPlatformLinux;
   RTC_LOG(LS_INFO) << "current platform is Linux";
 #elif defined(WEBRTC_IOS)
