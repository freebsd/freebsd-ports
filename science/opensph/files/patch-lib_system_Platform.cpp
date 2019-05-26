--- lib/system/Platform.cpp.orig	2019-05-26 03:11:41 UTC
+++ lib/system/Platform.cpp
@@ -8,14 +8,14 @@
 #include <string.h>
 #include <sys/stat.h>
 #include <sys/times.h>
-#include <sys/vtimes.h>
+//#include <sys/vtimes.h>
 #include <unistd.h>
 
 NAMESPACE_SPH_BEGIN
 
 Expected<Path> getExecutablePath() {
     char result[PATH_MAX];
-    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
+    ssize_t count = readlink("/proc/curproc/file", result, PATH_MAX);
     if (count != -1) {
         Path path(result);
         return path.parentPath();
@@ -103,14 +103,18 @@ class CpuUsage { (private)
 
 public:
     CpuUsage() {
+#if !defined(__FreeBSD__)
         FILE* file;
+#endif
         struct tms timeSample;
+#if !defined(__FreeBSD__)
         char line[128];
+#endif
 
         lastCpu = times(&timeSample);
         lastSysCpu = timeSample.tms_stime;
         lastUserCpu = timeSample.tms_utime;
-
+#if !defined(__FreeBSD__)
         file = fopen("/proc/cpuinfo", "r");
         numProcessors = 0;
         while (fgets(line, 128, file) != NULL) {
@@ -118,6 +122,8 @@ class CpuUsage { (private)
                 numProcessors++;
         }
         fclose(file);
+#endif
+      numProcessors = 8; // TODO
     }
 
     Optional<Float> getUsage() {
@@ -151,7 +157,7 @@ bool isDebuggerPresent() {
     char buf[1024];
     bool debuggerPresent = false;
 
-    int status_fd = open("/proc/self/status", O_RDONLY);
+    int status_fd = open("/proc/curproc/status", O_RDONLY);
     if (status_fd == -1) {
         return false;
     }
