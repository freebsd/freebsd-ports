--- src/3rdparty/chromium/media/capture/video/linux/video_capture_device_factory_v4l2.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/media/capture/video/linux/video_capture_device_factory_v4l2.cc
@@ -75,6 +75,9 @@ class DevVideoFilePathsDeviceProvider
     : public VideoCaptureDeviceFactoryV4L2::DeviceProvider {
  public:
   void GetDeviceIds(std::vector<std::string>* target_container) override {
+#if defined(OS_OPENBSD)
+    target_container->emplace_back("/dev/video");
+#else
     const base::FilePath path("/dev/");
     base::FileEnumerator enumerator(path, false, base::FileEnumerator::FILES,
                                     "video*");
@@ -82,9 +85,13 @@ class DevVideoFilePathsDeviceProvider
       const base::FileEnumerator::FileInfo info = enumerator.GetInfo();
       target_container->emplace_back(path.value() + info.GetName().value());
     }
+#endif
   }
 
   std::string GetDeviceModelId(const std::string& device_id) override {
+#if defined(OS_OPENBSD)
+    return std::string();
+#endif
     const std::string file_name = ExtractFileNameFromDeviceId(device_id);
     std::string usb_id;
     const std::string vid_path =
@@ -104,6 +111,9 @@ class DevVideoFilePathsDeviceProvider
   }
 
   std::string GetDeviceDisplayName(const std::string& device_id) override {
+#if defined(OS_OPENBSD)
+    return std::string();
+#endif
     const std::string file_name = ExtractFileNameFromDeviceId(device_id);
     const std::string interface_path =
         base::StringPrintf(kInterfacePathTemplate, file_name.c_str());
@@ -219,7 +229,7 @@ void VideoCaptureDeviceFactoryV4L2::GetDevicesInfo(
   std::move(callback).Run(std::move(devices_info));
 }
 
-int VideoCaptureDeviceFactoryV4L2::DoIoctl(int fd, int request, void* argp) {
+int VideoCaptureDeviceFactoryV4L2::DoIoctl(int fd, unsigned int request, void* argp) {
   return HANDLE_EINTR(v4l2_->ioctl(fd, request, argp));
 }
 
