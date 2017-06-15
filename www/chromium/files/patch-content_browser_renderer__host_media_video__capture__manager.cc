--- content/browser/renderer_host/media/video_capture_manager.cc.orig	2017-04-19 19:06:33 UTC
+++ content/browser/renderer_host/media/video_capture_manager.cc
@@ -645,7 +645,7 @@ VideoCaptureManager::DoStartTabCaptureOn
   DCHECK(IsOnDeviceThread());
 
   std::unique_ptr<VideoCaptureDevice> video_capture_device;
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
   video_capture_device = WebContentsVideoCaptureDevice::Create(id);
 #endif
 
@@ -675,7 +675,7 @@ VideoCaptureManager::DoStartDesktopCaptu
   }
 
   if (desktop_id.type == DesktopMediaID::TYPE_WEB_CONTENTS) {
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
     video_capture_device = WebContentsVideoCaptureDevice::Create(id);
     IncrementDesktopCaptureCounter(TAB_VIDEO_CAPTURER_CREATED);
     if (desktop_id.audio_share) {
