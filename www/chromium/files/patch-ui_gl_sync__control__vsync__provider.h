--- ui/gl/sync_control_vsync_provider.h.orig	2021-12-14 11:45:40 UTC
+++ ui/gl/sync_control_vsync_provider.h
@@ -30,11 +30,11 @@ class SyncControlVSyncProvider : public gfx::VSyncProv
   bool SupportGetVSyncParametersIfAvailable() const override;
 
   static constexpr bool IsSupported() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     return true;
 #else
     return false;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   }
 
  protected:
@@ -45,7 +45,7 @@ class SyncControlVSyncProvider : public gfx::VSyncProv
   virtual bool GetMscRate(int32_t* numerator, int32_t* denominator) = 0;
 
  private:
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   base::TimeTicks last_timebase_;
   uint64_t last_media_stream_counter_ = 0;
   base::TimeDelta last_good_interval_;
@@ -56,7 +56,7 @@ class SyncControlVSyncProvider : public gfx::VSyncProv
   // from configuration change (monitor reconfiguration, moving windows
   // between monitors, suspend and resume, etc.).
   base::queue<base::TimeDelta> last_computed_intervals_;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 };
 
 }  // namespace gl
