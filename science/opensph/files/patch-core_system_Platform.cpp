--- core/system/Platform.cpp.orig	2022-11-16 12:31:25 UTC
+++ core/system/Platform.cpp
@@ -117,14 +117,18 @@ class CpuUsage { (public)
 
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
@@ -132,6 +136,8 @@ class CpuUsage { (public)
                 numProcessors++;
         }
         fclose(file);
+#endif
+      numProcessors = 8; // TODO
     }
 
     Optional<Float> getUsage() {
@@ -176,7 +182,7 @@ bool isDebuggerPresent() {
     char buf[1024];
     bool debuggerPresent = false;
 
-    int status_fd = open("/proc/self/status", O_RDONLY);
+    int status_fd = open("/proc/curproc/status", O_RDONLY);
     if (status_fd == -1) {
         return false;
     }
