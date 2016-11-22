--- ui/gl/sync_control_vsync_provider.h.orig	2016-08-04 17:39:12.324777000 +0300
+++ ui/gl/sync_control_vsync_provider.h	2016-08-04 17:39:19.973676000 +0300
@@ -31,7 +31,7 @@
   virtual bool GetMscRate(int32_t* numerator, int32_t* denominator) = 0;
 
  private:
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::TimeTicks last_timebase_;
   uint64_t last_media_stream_counter_ = 0;
   base::TimeDelta last_good_interval_;
