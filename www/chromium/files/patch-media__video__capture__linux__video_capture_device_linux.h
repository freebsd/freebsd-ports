--- media/video/capture/linux/video_capture_device_linux.h.orig	2015-05-21 14:16:06.014473000 -0400
+++ media/video/capture/linux/video_capture_device_linux.h	2015-05-21 14:32:36.408695000 -0400
@@ -31,6 +31,7 @@
   explicit VideoCaptureDeviceLinux(const Name& device_name);
   ~VideoCaptureDeviceLinux() override;
 
+#if !defined(OS_FREEBSD)
   // VideoCaptureDevice implementation.
   void AllocateAndStart(const VideoCaptureParams& params,
                         scoped_ptr<Client> client) override;
@@ -38,6 +39,7 @@
 
  protected:
   void SetRotation(int rotation);
+#endif
 
  private:
   static int TranslatePowerLineFrequencyToV4L2(int frequency);
