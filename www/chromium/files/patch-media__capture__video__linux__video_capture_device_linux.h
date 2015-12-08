--- media/capture/video/linux/video_capture_device_linux.h.orig	2015-10-13 15:04:33.000000000 -0400
+++ media/capture/video/linux/video_capture_device_linux.h	2015-10-14 14:59:17.508402000 -0400
@@ -37,8 +37,10 @@
                         scoped_ptr<Client> client) override;
   void StopAndDeAllocate() override;
 
+#if !defined(OS_FREEBSD)
  protected:
   void SetRotation(int rotation);
+#endif  // !defined(OS_FREEBSD)
 
  private:
   static int TranslatePowerLineFrequencyToV4L2(int frequency);
