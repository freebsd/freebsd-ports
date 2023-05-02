--- media/capture/video/linux/v4l2_capture_delegate.cc.orig	2023-05-02 13:12:51 UTC
+++ media/capture/video/linux/v4l2_capture_delegate.cc
@@ -4,8 +4,10 @@
 
 #include "media/capture/video/linux/v4l2_capture_delegate.h"
 
+#if !BUILDFLAG(IS_BSD)
 #include <linux/version.h>
 #include <linux/videodev2.h>
+#endif
 #include <poll.h>
 #include <sys/fcntl.h>
 #include <sys/ioctl.h>
@@ -20,7 +22,6 @@
 #include "base/task/single_thread_task_runner.h"
 #include "base/trace_event/trace_event.h"
 #include "build/build_config.h"
-#include "media/base/bind_to_current_loop.h"
 #include "media/base/video_frame.h"
 #include "media/base/video_types.h"
 #include "media/capture/mojom/image_capture_types.h"
@@ -29,10 +30,12 @@
 
 using media::mojom::MeteringMode;
 
+#if !BUILDFLAG(IS_BSD)
 #if LINUX_VERSION_CODE < KERNEL_VERSION(4, 6, 0)
 // 16 bit depth, Realsense F200.
 #define V4L2_PIX_FMT_Z16 v4l2_fourcc('Z', '1', '6', ' ')
 #endif
+#endif
 
 // TODO(aleksandar.stojiljkovic): Wrap this with kernel version check once the
 // format is introduced to kernel.
@@ -139,47 +142,6 @@ int GetControllingSpecialControl(int control_id) {
   return 0;
 }
 
-// Determines if |control_id| is special, i.e. controls another one's state.
-bool IsSpecialControl(int control_id) {
-  switch (control_id) {
-    case V4L2_CID_AUTO_WHITE_BALANCE:
-    case V4L2_CID_EXPOSURE_AUTO:
-    case V4L2_CID_EXPOSURE_AUTO_PRIORITY:
-    case V4L2_CID_FOCUS_AUTO:
-      return true;
-  }
-  return false;
-}
-
-// Determines if |control_id| should be skipped, https://crbug.com/697885.
-#if !defined(V4L2_CID_PAN_SPEED)
-#define V4L2_CID_PAN_SPEED (V4L2_CID_CAMERA_CLASS_BASE + 32)
-#endif
-#if !defined(V4L2_CID_TILT_SPEED)
-#define V4L2_CID_TILT_SPEED (V4L2_CID_CAMERA_CLASS_BASE + 33)
-#endif
-#if !defined(V4L2_CID_PANTILT_CMD)
-#define V4L2_CID_PANTILT_CMD (V4L2_CID_CAMERA_CLASS_BASE + 34)
-#endif
-bool IsBlockedControl(int control_id) {
-  switch (control_id) {
-    case V4L2_CID_PAN_RELATIVE:
-    case V4L2_CID_TILT_RELATIVE:
-    case V4L2_CID_PAN_RESET:
-    case V4L2_CID_TILT_RESET:
-    case V4L2_CID_PAN_ABSOLUTE:
-    case V4L2_CID_TILT_ABSOLUTE:
-    case V4L2_CID_ZOOM_ABSOLUTE:
-    case V4L2_CID_ZOOM_RELATIVE:
-    case V4L2_CID_ZOOM_CONTINUOUS:
-    case V4L2_CID_PAN_SPEED:
-    case V4L2_CID_TILT_SPEED:
-    case V4L2_CID_PANTILT_CMD:
-      return true;
-  }
-  return false;
-}
-
 bool IsNonEmptyRange(const mojom::RangePtr& range) {
   return range->min < range->max;
 }
@@ -253,6 +215,49 @@ std::vector<uint32_t> V4L2CaptureDelegate::GetListOfUs
   return supported_formats;
 }
 
+// Determines if |control_id| is special, i.e. controls another one's state.
+// static
+bool V4L2CaptureDelegate::IsSpecialControl(int control_id) {
+  switch (control_id) {
+    case V4L2_CID_AUTO_WHITE_BALANCE:
+    case V4L2_CID_EXPOSURE_AUTO:
+    case V4L2_CID_EXPOSURE_AUTO_PRIORITY:
+    case V4L2_CID_FOCUS_AUTO:
+      return true;
+  }
+  return false;
+}
+
+// Determines if |control_id| should be skipped, https://crbug.com/697885.
+#if !defined(V4L2_CID_PAN_SPEED)
+#define V4L2_CID_PAN_SPEED (V4L2_CID_CAMERA_CLASS_BASE + 32)
+#endif
+#if !defined(V4L2_CID_TILT_SPEED)
+#define V4L2_CID_TILT_SPEED (V4L2_CID_CAMERA_CLASS_BASE + 33)
+#endif
+#if !defined(V4L2_CID_PANTILT_CMD)
+#define V4L2_CID_PANTILT_CMD (V4L2_CID_CAMERA_CLASS_BASE + 34)
+#endif
+// static
+bool V4L2CaptureDelegate::IsBlockedControl(int control_id) {
+  switch (control_id) {
+    case V4L2_CID_PAN_RELATIVE:
+    case V4L2_CID_TILT_RELATIVE:
+    case V4L2_CID_PAN_RESET:
+    case V4L2_CID_TILT_RESET:
+    case V4L2_CID_PAN_ABSOLUTE:
+    case V4L2_CID_TILT_ABSOLUTE:
+    case V4L2_CID_ZOOM_ABSOLUTE:
+    case V4L2_CID_ZOOM_RELATIVE:
+    case V4L2_CID_ZOOM_CONTINUOUS:
+    case V4L2_CID_PAN_SPEED:
+    case V4L2_CID_TILT_SPEED:
+    case V4L2_CID_PANTILT_CMD:
+      return true;
+  }
+  return false;
+}
+
 V4L2CaptureDelegate::V4L2CaptureDelegate(
     V4L2CaptureDevice* v4l2,
     const VideoCaptureDeviceDescriptor& device_descriptor,
@@ -728,7 +733,7 @@ base::WeakPtr<V4L2CaptureDelegate> V4L2CaptureDelegate
 
 V4L2CaptureDelegate::~V4L2CaptureDelegate() = default;
 
-bool V4L2CaptureDelegate::RunIoctl(int request, void* argp) {
+bool V4L2CaptureDelegate::RunIoctl(unsigned int request, void* argp) {
   int num_retries = 0;
   for (; DoIoctl(request, argp) < 0 && num_retries < kMaxIOCtrlRetries;
        ++num_retries) {
@@ -738,7 +743,7 @@ bool V4L2CaptureDelegate::RunIoctl(int request, void* 
   return num_retries != kMaxIOCtrlRetries;
 }
 
-int V4L2CaptureDelegate::DoIoctl(int request, void* argp) {
+int V4L2CaptureDelegate::DoIoctl(unsigned int request, void* argp) {
   return HANDLE_EINTR(v4l2_->ioctl(device_fd_.get(), request, argp));
 }
 
@@ -778,6 +783,7 @@ bool V4L2CaptureDelegate::IsControllableControl(int co
 }
 
 void V4L2CaptureDelegate::ReplaceControlEventSubscriptions() {
+#if !BUILDFLAG(IS_BSD)
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
@@ -829,100 +836,89 @@ mojom::RangePtr V4L2CaptureDelegate::RetrieveUserContr
 }
 
 void V4L2CaptureDelegate::ResetUserAndCameraControlsToDefault() {
-  // Set V4L2_CID_AUTO_WHITE_BALANCE to false first.
-  v4l2_control auto_white_balance = {};
-  auto_white_balance.id = V4L2_CID_AUTO_WHITE_BALANCE;
-  auto_white_balance.value = false;
-  if (!RunIoctl(VIDIOC_S_CTRL, &auto_white_balance))
-    return;
-
-  std::vector<struct v4l2_ext_control> special_camera_controls;
-  // Set V4L2_CID_EXPOSURE_AUTO to V4L2_EXPOSURE_MANUAL.
-  v4l2_ext_control auto_exposure = {};
-  auto_exposure.id = V4L2_CID_EXPOSURE_AUTO;
-  auto_exposure.value = V4L2_EXPOSURE_MANUAL;
-  special_camera_controls.push_back(auto_exposure);
-  // Set V4L2_CID_EXPOSURE_AUTO_PRIORITY to false.
-  v4l2_ext_control priority_auto_exposure = {};
-  priority_auto_exposure.id = V4L2_CID_EXPOSURE_AUTO_PRIORITY;
-  priority_auto_exposure.value = false;
-  special_camera_controls.push_back(priority_auto_exposure);
-  // Set V4L2_CID_FOCUS_AUTO to false.
-  v4l2_ext_control auto_focus = {};
-  auto_focus.id = V4L2_CID_FOCUS_AUTO;
-  auto_focus.value = false;
-  special_camera_controls.push_back(auto_focus);
-
   struct v4l2_ext_controls ext_controls = {};
-  ext_controls.ctrl_class = V4L2_CID_CAMERA_CLASS;
-  ext_controls.count = special_camera_controls.size();
-  ext_controls.controls = special_camera_controls.data();
-  if (DoIoctl(VIDIOC_S_EXT_CTRLS, &ext_controls) < 0)
-    DPLOG(INFO) << "VIDIOC_S_EXT_CTRLS";
+  ext_controls.which = V4L2_CTRL_WHICH_CUR_VAL;
+  ext_controls.count = 0;
+  const bool use_modern_s_ext_ctrls =
+      DoIoctl(VIDIOC_S_EXT_CTRLS, &ext_controls) == 0;
 
   for (const auto& control : kControls) {
     std::vector<struct v4l2_ext_control> camera_controls;
+    std::vector<struct v4l2_ext_control> manual_special_camera_controls;
+    std::vector<struct v4l2_ext_control> special_camera_controls;
 
     v4l2_queryctrl range = {};
-    range.id = control.control_base | V4L2_CTRL_FLAG_NEXT_CTRL;
+    // Start right below the base so that the first next retrieved control ID
+    // is always the first available control ID within the class even if that
+    // control ID is equal to the base (V4L2_CID_BRIGHTNESS equals to
+    // V4L2_CID_USER_BASE).
+    range.id = (control.control_base - 1) | V4L2_CTRL_FLAG_NEXT_CTRL;
     while (0 == DoIoctl(VIDIOC_QUERYCTRL, &range)) {
       if (V4L2_CTRL_ID2CLASS(range.id) != V4L2_CTRL_ID2CLASS(control.class_id))
         break;
+
+      v4l2_ext_control ext_control = {};
+      ext_control.id = range.id;
+      ext_control.value = range.default_value;
+
+      // Prepare to query for the next control as `range` is an in-out
+      // parameter.
       range.id |= V4L2_CTRL_FLAG_NEXT_CTRL;
 
-      if (IsSpecialControl(range.id & ~V4L2_CTRL_FLAG_NEXT_CTRL))
+      if (range.flags & (V4L2_CTRL_FLAG_DISABLED | V4L2_CTRL_FLAG_READ_ONLY)) {
+        // Permanently disabled or permanently read-only.
         continue;
-      if (IsBlockedControl(range.id & ~V4L2_CTRL_FLAG_NEXT_CTRL))
+      }
+      if (IsBlockedControl(ext_control.id)) {
         continue;
+      }
 
-      struct v4l2_ext_control ext_control = {};
-      ext_control.id = range.id & ~V4L2_CTRL_FLAG_NEXT_CTRL;
-      ext_control.value = range.default_value;
-      camera_controls.push_back(ext_control);
+      if (IsSpecialControl(ext_control.id)) {
+        special_camera_controls.push_back(ext_control);
+        if (ext_control.id == V4L2_CID_EXPOSURE_AUTO) {
+          ext_control.value = V4L2_EXPOSURE_MANUAL;
+        } else {
+          ext_control.value = false;  // Not automatic but manual.
+        }
+        manual_special_camera_controls.push_back(ext_control);
+      } else {
+        camera_controls.push_back(ext_control);
+      }
     }
 
     if (!camera_controls.empty()) {
-      struct v4l2_ext_controls ext_controls2 = {};
-      ext_controls2.ctrl_class = control.class_id;
-      ext_controls2.count = camera_controls.size();
-      ext_controls2.controls = camera_controls.data();
-      if (DoIoctl(VIDIOC_S_EXT_CTRLS, &ext_controls2) < 0)
+      // Set special controls to manual modes first.
+      if (!manual_special_camera_controls.empty()) {
+        ext_controls.which =
+            use_modern_s_ext_ctrls ? V4L2_CTRL_WHICH_CUR_VAL : control.class_id;
+        ext_controls.count = manual_special_camera_controls.size();
+        ext_controls.controls = manual_special_camera_controls.data();
+        if (DoIoctl(VIDIOC_S_EXT_CTRLS, &ext_controls) < 0) {
+          DPLOG(INFO) << "VIDIOC_S_EXT_CTRLS";
+        }
+      }
+
+      // Set non-special controls to the default values.
+      ext_controls.which =
+          use_modern_s_ext_ctrls ? V4L2_CTRL_WHICH_CUR_VAL : control.class_id;
+      ext_controls.count = camera_controls.size();
+      ext_controls.controls = camera_controls.data();
+      if (DoIoctl(VIDIOC_S_EXT_CTRLS, &ext_controls) < 0) {
         DPLOG(INFO) << "VIDIOC_S_EXT_CTRLS";
+      }
     }
-  }
 
-  // Now set the special flags to the default values
-  v4l2_queryctrl range = {};
-  range.id = V4L2_CID_AUTO_WHITE_BALANCE;
-  DoIoctl(VIDIOC_QUERYCTRL, &range);
-  auto_white_balance.value = range.default_value;
-  DoIoctl(VIDIOC_S_CTRL, &auto_white_balance);
-
-  special_camera_controls.clear();
-  memset(&range, 0, sizeof(range));
-  range.id = V4L2_CID_EXPOSURE_AUTO;
-  DoIoctl(VIDIOC_QUERYCTRL, &range);
-  auto_exposure.value = range.default_value;
-  special_camera_controls.push_back(auto_exposure);
-
-  memset(&range, 0, sizeof(range));
-  range.id = V4L2_CID_EXPOSURE_AUTO_PRIORITY;
-  DoIoctl(VIDIOC_QUERYCTRL, &range);
-  priority_auto_exposure.value = range.default_value;
-  special_camera_controls.push_back(priority_auto_exposure);
-
-  memset(&range, 0, sizeof(range));
-  range.id = V4L2_CID_FOCUS_AUTO;
-  DoIoctl(VIDIOC_QUERYCTRL, &range);
-  auto_focus.value = range.default_value;
-  special_camera_controls.push_back(auto_focus);
-
-  memset(&ext_controls, 0, sizeof(ext_controls));
-  ext_controls.ctrl_class = V4L2_CID_CAMERA_CLASS;
-  ext_controls.count = special_camera_controls.size();
-  ext_controls.controls = special_camera_controls.data();
-  if (DoIoctl(VIDIOC_S_EXT_CTRLS, &ext_controls) < 0)
-    DPLOG(INFO) << "VIDIOC_S_EXT_CTRLS";
+    // Set special controls to the default values.
+    if (!special_camera_controls.empty()) {
+      ext_controls.which =
+          use_modern_s_ext_ctrls ? V4L2_CTRL_WHICH_CUR_VAL : control.class_id;
+      ext_controls.count = special_camera_controls.size();
+      ext_controls.controls = special_camera_controls.data();
+      if (DoIoctl(VIDIOC_S_EXT_CTRLS, &ext_controls) < 0) {
+        DPLOG(INFO) << "VIDIOC_S_EXT_CTRLS";
+      }
+    }
+  }
 }
 
 bool V4L2CaptureDelegate::MapAndQueueBuffer(int index) {
@@ -985,7 +981,11 @@ void V4L2CaptureDelegate::DoCapture() {
 
   pollfd device_pfd = {};
   device_pfd.fd = device_fd_.get();
+#if !BUILDFLAG(IS_BSD)
   device_pfd.events = POLLIN | POLLPRI;
+#else
+  device_pfd.events = POLLIN;
+#endif
 
   const int result =
       HANDLE_EINTR(v4l2_->poll(&device_pfd, 1, kCaptureTimeoutMs));
@@ -1023,6 +1023,7 @@ void V4L2CaptureDelegate::DoCapture() {
     timeout_count_ = 0;
   }
 
+#if !BUILDFLAG(IS_BSD)
   // Dequeue events if the driver has filled in some.
   if (device_pfd.revents & POLLPRI) {
     bool controls_changed = false;
@@ -1057,6 +1058,7 @@ void V4L2CaptureDelegate::DoCapture() {
       client_->OnCaptureConfigurationChanged();
     }
   }
+#endif
 
   // Deenqueue, send and reenqueue a buffer if the driver has filled one in.
   if (device_pfd.revents & POLLIN) {
