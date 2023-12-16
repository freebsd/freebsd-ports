--- src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_delegate.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_delegate.cc
@@ -4,8 +4,10 @@
 
 #include "media/capture/video/linux/v4l2_capture_delegate.h"
 
+#if !defined(OS_BSD)
 #include <linux/version.h>
 #include <linux/videodev2.h>
+#endif
 #include <poll.h>
 #include <sys/fcntl.h>
 #include <sys/ioctl.h>
@@ -29,10 +31,10 @@
 
 using media::mojom::MeteringMode;
 
-#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 6, 0)
+// #if LINUX_VERSION_CODE < KERNEL_VERSION(4, 6, 0)
 // 16 bit depth, Realsense F200.
 #define V4L2_PIX_FMT_Z16 v4l2_fourcc('Z', '1', '6', ' ')
-#endif
+// #endif
 
 // TODO(aleksandar.stojiljkovic): Wrap this with kernel version check once the
 // format is introduced to kernel.
@@ -728,7 +730,7 @@ base::WeakPtr<V4L2CaptureDelegate> V4L2CaptureDelegate
 
 V4L2CaptureDelegate::~V4L2CaptureDelegate() = default;
 
-bool V4L2CaptureDelegate::RunIoctl(int request, void* argp) {
+bool V4L2CaptureDelegate::RunIoctl(unsigned int request, void* argp) {
   int num_retries = 0;
   for (; DoIoctl(request, argp) < 0 && num_retries < kMaxIOCtrlRetries;
        ++num_retries) {
@@ -738,7 +740,7 @@ bool V4L2CaptureDelegate::RunIoctl(int request, void* 
   return num_retries != kMaxIOCtrlRetries;
 }
 
-int V4L2CaptureDelegate::DoIoctl(int request, void* argp) {
+int V4L2CaptureDelegate::DoIoctl(unsigned int request, void* argp) {
   return HANDLE_EINTR(v4l2_->ioctl(device_fd_.get(), request, argp));
 }
 
@@ -778,6 +780,10 @@ bool V4L2CaptureDelegate::IsControllableControl(int co
 }
 
 void V4L2CaptureDelegate::ReplaceControlEventSubscriptions() {
+// these ioctls are not implemented on *BSDs
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+#else
   constexpr uint32_t kControlIds[] = {V4L2_CID_AUTO_EXPOSURE_BIAS,
                                       V4L2_CID_AUTO_WHITE_BALANCE,
                                       V4L2_CID_BRIGHTNESS,
@@ -805,6 +811,7 @@ void V4L2CaptureDelegate::ReplaceControlEventSubscript
                   << ", {type = V4L2_EVENT_CTRL, id = " << control_id << "}";
     }
   }
+#endif
 }
 
 mojom::RangePtr V4L2CaptureDelegate::RetrieveUserControlRange(int control_id) {
