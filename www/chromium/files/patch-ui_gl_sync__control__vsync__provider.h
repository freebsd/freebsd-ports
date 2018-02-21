--- ui/gl/sync_control_vsync_provider.h.orig	2017-12-15 02:04:52.000000000 +0100
+++ ui/gl/sync_control_vsync_provider.h	2017-12-24 20:29:58.843365000 +0100
@@ -23,11 +23,11 @@
   void GetVSyncParameters(const UpdateVSyncCallback& callback) override;
 
   static constexpr bool IsSupported() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     return true;
 #else
     return false;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
   }
 
  protected:
@@ -38,7 +38,7 @@
   virtual bool GetMscRate(int32_t* numerator, int32_t* denominator) = 0;
 
  private:
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::TimeTicks last_timebase_;
   uint64_t last_media_stream_counter_ = 0;
   base::TimeDelta last_good_interval_;
@@ -49,7 +49,7 @@
   // from configuration change (monitor reconfiguration, moving windows
   // between monitors, suspend and resume, etc.).
   base::queue<base::TimeDelta> last_computed_intervals_;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   DISALLOW_COPY_AND_ASSIGN(SyncControlVSyncProvider);
 };
