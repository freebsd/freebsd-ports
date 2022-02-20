--- third_party/webrtc/modules/desktop_capture/linux/x_server_pixel_buffer.cc.orig	2022-02-07 13:39:41 UTC
+++ third_party/webrtc/modules/desktop_capture/linux/x_server_pixel_buffer.cc
@@ -213,6 +213,13 @@ void XServerPixelBuffer::InitShm(const XWindowAttribut
   Visual* default_visual = attributes.visual;
   int default_depth = attributes.depth;
 
+#if defined(__OpenBSD__)
+  // pledge(2)
+  RTC_LOG(LS_WARNING) << "Unable to use shmget(2) while using pledge(2). "
+                         "Performance may be degraded.";
+  return;
+#endif
+
   int major, minor;
   Bool have_pixmaps;
   if (!XShmQueryVersion(display_, &major, &minor, &have_pixmaps)) {
