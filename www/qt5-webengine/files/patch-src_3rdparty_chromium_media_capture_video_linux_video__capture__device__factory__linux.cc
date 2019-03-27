--- src/3rdparty/chromium/media/capture/video/linux/video_capture_device_factory_linux.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/media/capture/video/linux/video_capture_device_factory_linux.cc
@@ -253,6 +253,7 @@ bool VideoCaptureDeviceFactoryLinux::HasUsableFormats(
   if (!(capabilities & V4L2_CAP_VIDEO_CAPTURE))
     return false;
 
+#if !defined(OS_FREEBSD)
   const std::list<uint32_t>& usable_fourccs =
       VideoCaptureDeviceLinux::GetListOfUsableFourCCs(false);
   v4l2_fmtdesc fmtdesc = {};
@@ -264,6 +265,7 @@ bool VideoCaptureDeviceFactoryLinux::HasUsableFormats(
       return true;
     }
   }
+#endif
 
   DLOG(ERROR) << "No usable formats found";
   return false;
@@ -311,9 +313,13 @@ void VideoCaptureDeviceFactoryLinux::GetSupportedForma
   for (; HANDLE_EINTR(v4l2_->ioctl(fd, VIDIOC_ENUM_FMT, &v4l2_format)) == 0;
        ++v4l2_format.index) {
     VideoCaptureFormat supported_format;
+#if !defined(OS_FREEBSD)
     supported_format.pixel_format =
         VideoCaptureDeviceLinux::V4l2FourCcToChromiumPixelFormat(
             v4l2_format.pixelformat);
+#else
+    supported_format.pixel_format = PIXEL_FORMAT_UNKNOWN;
+#endif
 
     if (supported_format.pixel_format == PIXEL_FORMAT_UNKNOWN)
       continue;
