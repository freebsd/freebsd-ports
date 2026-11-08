--- client/app.cpp.orig	2025-11-24 08:44:26 UTC
+++ client/app.cpp
@@ -539,7 +539,7 @@ void ACTIVE_TASK_SET::get_memory_usage() {
     // compute non_boinc_cpu_usage
     non_boinc_cpu_usage = 0;
 
-#if defined(__linux__) || defined(_WIN32) || defined(__APPLE__)
+#if defined(__linux__) || defined(_WIN32) || defined(__APPLE__) || defined(__FreeBSD__)
 #ifndef ANDROID
     // Improved version for systems where we can get total CPU
     // (Win, Linux, Mac)
