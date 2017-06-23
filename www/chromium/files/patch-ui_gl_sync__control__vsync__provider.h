--- ui/gl/sync_control_vsync_provider.h.orig	2017-06-05 19:03:30 UTC
+++ ui/gl/sync_control_vsync_provider.h
@@ -39,7 +39,7 @@ class SyncControlVSyncProvider : public gfx::VSyncProv
   virtual bool GetMscRate(int32_t* numerator, int32_t* denominator) = 0;
 
  private:
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::TimeTicks last_timebase_;
   uint64_t last_media_stream_counter_ = 0;
   base::TimeDelta last_good_interval_;
@@ -50,7 +50,7 @@ class SyncControlVSyncProvider : public gfx::VSyncProv
   // from configuration change (monitor reconfiguration, moving windows
   // between monitors, suspend and resume, etc.).
   std::queue<base::TimeDelta> last_computed_intervals_;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   DISALLOW_COPY_AND_ASSIGN(SyncControlVSyncProvider);
 };
