--- media/capture/video/linux/v4l2_capture_delegate.cc.orig	2025-09-11 13:19:19 UTC
+++ media/capture/video/linux/v4l2_capture_delegate.cc
@@ -10,8 +10,10 @@
 #include "media/capture/video/linux/v4l2_capture_delegate.h"
 
 #include <fcntl.h>
+#if !BUILDFLAG(IS_BSD)
 #include <linux/version.h>
 #include <linux/videodev2.h>
+#endif
 #include <poll.h>
 #include <sys/ioctl.h>
 #include <sys/mman.h>
@@ -35,17 +37,19 @@
 #include "media/capture/video/blob_utils.h"
 #include "media/capture/video/linux/video_capture_device_linux.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "media/capture/capture_switches.h"
 #include "media/capture/video/linux/v4l2_capture_delegate_gpu_helper.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
 using media::mojom::MeteringMode;
 
+#if !BUILDFLAG(IS_BSD)
 #if LINUX_VERSION_CODE < KERNEL_VERSION(4, 6, 0)
 // 16 bit depth, Realsense F200.
 #define V4L2_PIX_FMT_Z16 v4l2_fourcc('Z', '1', '6', ' ')
 #endif
+#endif
 
 // TODO(aleksandar.stojiljkovic): Wrap this with kernel version check once the
 // format is introduced to kernel.
@@ -55,6 +59,14 @@ using media::mojom::MeteringMode;
 #define V4L2_PIX_FMT_INVZ v4l2_fourcc('I', 'N', 'V', 'Z')
 #endif
 
+#ifndef V4L2_COLORSPACE_OPRGB
+#define V4L2_COLORSPACE_OPRGB V4L2_COLORSPACE_ADOBERGB
+#endif
+
+#ifndef V4L2_XFER_FUNC_OPRGB
+#define V4L2_XFER_FUNC_OPRGB V4L2_XFER_FUNC_ADOBERGB
+#endif
+
 namespace media {
 
 namespace {
@@ -274,7 +286,7 @@ bool V4L2CaptureDelegate::IsBlockedControl(int control
 // static
 bool V4L2CaptureDelegate::IsControllableControl(
     int control_id,
-    const base::RepeatingCallback<int(int, void*)>& do_ioctl) {
+    const base::RepeatingCallback<int(unsigned int, void*)>& do_ioctl) {
   const int special_control_id = GetControllingSpecialControl(control_id);
   if (!special_control_id) {
     // The control is not controlled by a special control thus the control is
@@ -330,7 +342,7 @@ V4L2CaptureDelegate::V4L2CaptureDelegate(
       is_capturing_(false),
       timeout_count_(0),
       rotation_(rotation) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   use_gpu_buffer_ = switches::IsVideoCaptureUseGpuMemoryBufferEnabled();
 #endif  // BUILDFLAG(IS_LINUX)
 }
@@ -457,7 +469,7 @@ void V4L2CaptureDelegate::AllocateAndStart(
 
   client_->OnStarted();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (use_gpu_buffer_) {
     v4l2_gpu_helper_ = std::make_unique<V4L2CaptureDelegateGpuHelper>();
   }
@@ -801,7 +813,7 @@ base::WeakPtr<V4L2CaptureDelegate> V4L2CaptureDelegate
 
 V4L2CaptureDelegate::~V4L2CaptureDelegate() = default;
 
-bool V4L2CaptureDelegate::RunIoctl(int request, void* argp) {
+bool V4L2CaptureDelegate::RunIoctl(unsigned int request, void* argp) {
   int num_retries = 0;
   for (; DoIoctl(request, argp) < 0 && num_retries < kMaxIOCtrlRetries;
        ++num_retries) {
@@ -811,7 +823,7 @@ bool V4L2CaptureDelegate::RunIoctl(int request, void* 
   return num_retries != kMaxIOCtrlRetries;
 }
 
-int V4L2CaptureDelegate::DoIoctl(int request, void* argp) {
+int V4L2CaptureDelegate::DoIoctl(unsigned int request, void* argp) {
   return HANDLE_EINTR(v4l2_->ioctl(device_fd_.get(), request, argp));
 }
 
@@ -822,6 +834,7 @@ bool V4L2CaptureDelegate::IsControllableControl(int co
 }
 
 void V4L2CaptureDelegate::ReplaceControlEventSubscriptions() {
+#if !BUILDFLAG(IS_BSD)
   constexpr uint32_t kControlIds[] = {V4L2_CID_AUTO_EXPOSURE_BIAS,
                                       V4L2_CID_AUTO_WHITE_BALANCE,
                                       V4L2_CID_BRIGHTNESS,
@@ -849,6 +862,7 @@ void V4L2CaptureDelegate::ReplaceControlEventSubscript
                   << ", {type = V4L2_EVENT_CTRL, id = " << control_id << "}";
     }
   }
+#endif
 }
 
 mojom::RangePtr V4L2CaptureDelegate::RetrieveUserControlRange(int control_id) {
@@ -1029,7 +1043,11 @@ void V4L2CaptureDelegate::DoCapture() {
 
   pollfd device_pfd = {};
   device_pfd.fd = device_fd_.get();
+#if !BUILDFLAG(IS_BSD)
   device_pfd.events = POLLIN | POLLPRI;
+#else
+  device_pfd.events = POLLIN;
+#endif
 
   const int result =
       HANDLE_EINTR(v4l2_->poll(&device_pfd, 1, kCaptureTimeoutMs));
@@ -1067,6 +1085,7 @@ void V4L2CaptureDelegate::DoCapture() {
     timeout_count_ = 0;
   }
 
+#if !BUILDFLAG(IS_BSD)
   // Dequeue events if the driver has filled in some.
   if (device_pfd.revents & POLLPRI) {
     bool controls_changed = false;
@@ -1100,6 +1119,7 @@ void V4L2CaptureDelegate::DoCapture() {
       client_->OnCaptureConfigurationChanged();
     }
   }
+#endif
 
   // Deenqueue, send and reenqueue a buffer if the driver has filled one in.
   if (device_pfd.revents & POLLIN) {
@@ -1153,7 +1173,7 @@ void V4L2CaptureDelegate::DoCapture() {
       // workable on Linux.
 
       // See http://crbug.com/959919.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       if (use_gpu_buffer_) {
         v4l2_gpu_helper_->OnIncomingCapturedData(
             client_.get(), buffer_tracker->start(),
@@ -1227,7 +1247,7 @@ void V4L2CaptureDelegate::SetErrorState(VideoCaptureEr
   client_->OnError(error, from_here, reason);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 gfx::ColorSpace V4L2CaptureDelegate::BuildColorSpaceFromv4l2() {
   v4l2_colorspace v4l2_primary = (v4l2_colorspace)video_fmt_.fmt.pix.colorspace;
   v4l2_quantization v4l2_range =
