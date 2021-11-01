--- cpuid.c.orig	2021-11-01 17:25:27 UTC
+++ cpuid.c
@@ -73,6 +73,8 @@
 #define USE_CPUID_COUNT
 #endif
 
+#define CPUID_MAJOR 0
+
 #if defined(__GNUC__)
 #define UNUSED __attribute((unused))
 #else
@@ -9485,12 +9487,17 @@ real_setup(unsigned int  cpu,
          pthread_t thread = pthread_self();
          int status = processor_bind(P_LWPID, thread, cpu, NULL);
 #else
-         cpu_set_t  cpuset;
+         cpuset_t  cpuset;
          CPU_ZERO(&cpuset);
          CPU_SET(cpu, &cpuset);
          int  status;
-         status = sched_setaffinity(0, sizeof(cpu_set_t), &cpuset);
+#if defined(__FreeBSD__)
+         status = cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID,
+           -1, sizeof(cpuset_t), &cpuset);
+#else
+         status = sched_setaffinity(0, sizeof(cpuset_t), &cpuset);
 #endif
+#endif
          if (status == -1) {
             if (cpu > 0) {
                if (errno == EINVAL) return -1;
@@ -9613,11 +9620,14 @@ static int real_get (int           cpuid_fd,
             "c" (ecx));
 #endif
    } else {
-      off64_t  result;
-      off64_t  offset = ((off64_t)ecx << 32) + reg;
+//    off64_t  result;
+//    off64_t  offset = ((off64_t)ecx << 32) + reg;
+      int32_t  result;
+      int32_t  offset = (int32_t)ecx + reg;
       int      status;
 
-      result = lseek64(cpuid_fd, offset, SEEK_SET);
+//    result = lseek64(cpuid_fd, offset, SEEK_SET);
+      result = lseek(cpuid_fd, offset, SEEK_SET);
       if (result == -1) {
          if (quiet) {
             return FALSE;
