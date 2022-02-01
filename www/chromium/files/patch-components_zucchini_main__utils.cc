--- components/zucchini/main_utils.cc.orig	2021-12-31 00:57:31 UTC
+++ components/zucchini/main_utils.cc
@@ -80,7 +80,7 @@ constexpr Command kCommands[] = {
 
 /******** GetPeakMemoryMetrics ********/
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Linux does not have an exact mapping to the values used on Windows so use a
 // close approximation:
 // peak_virtual_memory ~= peak_page_file_usage
@@ -122,7 +122,7 @@ void GetPeakMemoryMetrics(size_t* peak_virtual_memory,
     }
   }
 }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 // On failure the input values will be set to 0.
@@ -147,17 +147,17 @@ class ScopedResourceUsageTracker {
   ScopedResourceUsageTracker() {
     start_time_ = base::TimeTicks::Now();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_BSD)
     GetPeakMemoryMetrics(&start_peak_page_file_usage_,
                          &start_peak_working_set_size_);
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_BSD)
   }
 
   // Computes and prints usage.
   ~ScopedResourceUsageTracker() {
     base::TimeTicks end_time = base::TimeTicks::Now();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_BSD)
     size_t cur_peak_page_file_usage = 0;
     size_t cur_peak_working_set_size = 0;
     GetPeakMemoryMetrics(&cur_peak_page_file_usage, &cur_peak_working_set_size);
@@ -173,7 +173,7 @@ class ScopedResourceUsageTracker {
               << (cur_peak_working_set_size - start_peak_working_set_size_) /
                      1024
               << " KiB";
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_BSD)
 
     LOG(INFO) << "Zucchini.TotalTime " << (end_time - start_time_).InSecondsF()
               << " s";
@@ -181,10 +181,10 @@ class ScopedResourceUsageTracker {
 
  private:
   base::TimeTicks start_time_;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_BSD)
   size_t start_peak_page_file_usage_ = 0;
   size_t start_peak_working_set_size_ = 0;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_BSD)
 };
 
 /******** Helper functions ********/
