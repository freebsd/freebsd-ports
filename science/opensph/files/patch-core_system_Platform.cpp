--- core/system/Platform.cpp.orig	2021-04-08 21:23:28 UTC
+++ core/system/Platform.cpp
@@ -102,14 +106,18 @@ class CpuUsage { (private)
 
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
@@ -117,6 +125,8 @@ class CpuUsage { (private)
                 numProcessors++;
         }
         fclose(file);
+#endif
+      numProcessors = 8; // TODO
     }
 
     Optional<Float> getUsage() {
@@ -150,7 +160,7 @@ bool isDebuggerPresent() {
     char buf[1024];
     bool debuggerPresent = false;
 
-    int status_fd = open("/proc/self/status", O_RDONLY);
+    int status_fd = open("/proc/curproc/status", O_RDONLY);
     if (status_fd == -1) {
         return false;
     }
