--- content/browser/renderer_host/media/in_process_video_capture_device_launcher.cc.orig	2017-08-02 18:58:22.340485000 +0200
+++ content/browser/renderer_host/media/in_process_video_capture_device_launcher.cc	2017-08-02 18:58:52.538400000 +0200
@@ -233,7 +233,7 @@
   DCHECK(device_task_runner_->BelongsToCurrentThread());
 
   std::unique_ptr<media::VideoCaptureDevice> video_capture_device;
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
   video_capture_device = WebContentsVideoCaptureDevice::Create(id);
 #endif
 
@@ -264,7 +264,7 @@
   }
 
   if (desktop_id.type == DesktopMediaID::TYPE_WEB_CONTENTS) {
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
     video_capture_device = WebContentsVideoCaptureDevice::Create(id);
     IncrementDesktopCaptureCounter(TAB_VIDEO_CAPTURER_CREATED);
     if (desktop_id.audio_share) {
