--- src/3rdparty/chromium/ui/gl/sync_control_vsync_provider.h.orig	2017-01-26 00:49:32 UTC
+++ src/3rdparty/chromium/ui/gl/sync_control_vsync_provider.h
@@ -32,7 +32,7 @@ class GL_EXPORT SyncControlVSyncProvider
   virtual bool GetMscRate(int32_t* numerator, int32_t* denominator) = 0;
 
  private:
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_WIN)
   bool AdjustSyncValues(int64_t* system_time, int64_t* media_stream_counter);
 
   base::TimeTicks last_timebase_;
@@ -46,11 +46,11 @@ class GL_EXPORT SyncControlVSyncProvider
   // from configuration change (monitor reconfiguration, moving windows
   // between monitors, suspend and resume, etc.).
   std::queue<base::TimeDelta> last_computed_intervals_;
-#endif  //  defined(OS_LINUX) || defined(OS_WIN)
+#endif  //  defined(OS_LINUX) || defined(OS_BSD) || defined(OS_WIN)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   bool invalid_msc_ = false;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   DISALLOW_COPY_AND_ASSIGN(SyncControlVSyncProvider);
 };
