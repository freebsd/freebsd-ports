--- src/web/FileUtils.C.orig	2025-12-02 04:12:42 UTC
+++ src/web/FileUtils.C
@@ -72,7 +72,7 @@ namespace Wt {
   #ifndef WT_FILESYSTEM_IMPL_STD_CLOCK_17
       auto ftime = Wt::cpp17::filesystem::last_write_time(file);
       auto systime = decltype(ftime)::clock::to_sys(ftime);
-      return std::chrono::system_clock::from_time_t(decltype(systime)::clock::to_time_t(systime));
+      return std::chrono::system_clock::time_point(std::chrono::duration_cast<std::chrono::system_clock::duration>(systime.time_since_epoch()));
   #else // WT_FILESYSTEM_IMPL_STD_CLOCK_17
       LOG_DEBUG("When using cpp17 or lower with std::filesystem, the result of this function is an approximation. Use boost::filesystem, instead of std::filesystem (see WT_CPP17_FILESYSTEM_IMPLEMENTATION) if this is a problem for your application.");
       auto ftime = Wt::cpp17::filesystem::last_write_time(file);
