commit 324c4811690dd288a7bbd1378d129dc5e9d6f16b

    video capture also is implented with WEBRTC_BSD (at least on FreeBSD)

diff --git third_party/libwebrtc/modules/video_capture/video_capture_factory.cc third_party/libwebrtc/modules/video_capture/video_capture_factory.cc
index e085ac2df8a0..2790fbbe1cba 100644
--- third_party/libwebrtc/modules/video_capture/video_capture_factory.cc
+++ third_party/libwebrtc/modules/video_capture/video_capture_factory.cc
@@ -24,7 +24,7 @@ rtc::scoped_refptr<VideoCaptureModule> VideoCaptureFactory::Create(
     const char* deviceUniqueIdUTF8) {
 // This is only implemented on pure Linux and WEBRTC_LINUX is defined for
 // Android as well
-#if !defined(WEBRTC_LINUX) || defined(WEBRTC_ANDROID)
+#if (!defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)) || defined(WEBRTC_ANDROID)
   return nullptr;
 #else
   return videocapturemodule::VideoCaptureImpl::Create(options,
@@ -40,7 +40,7 @@ VideoCaptureModule::DeviceInfo* VideoCaptureFactory::CreateDeviceInfo(
     VideoCaptureOptions* options) {
 // This is only implemented on pure Linux and WEBRTC_LINUX is defined for
 // Android as well
-#if !defined(WEBRTC_LINUX) || defined(WEBRTC_ANDROID)
+#if (!defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)) || defined(WEBRTC_ANDROID)
   return nullptr;
 #else
   return videocapturemodule::VideoCaptureImpl::CreateDeviceInfo(options);
