--- cpuid.c.orig	2020-01-22 16:55:23 UTC
+++ cpuid.c
@@ -33,12 +33,15 @@
 #ifdef __linux__
 #define USE_CPUID_MODULE
 #define USE_KERNEL_SCHED_SETAFFINITY
+#include <sys/sysmacros.h>
 #endif
 
 #if __GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__ >= 40300
 #define USE_CPUID_COUNT
 #endif
 
+#define CPUID_MAJOR 0
+
 #if defined(__GNUC__)
 #define UNUSED __attribute((unused))
 #else
@@ -49,7 +52,6 @@
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <sys/sysmacros.h>
 #include <fcntl.h>
 #include <errno.h>
 #include <unistd.h>
@@ -57,6 +59,8 @@
 #include <string.h>
 #include <regex.h>
 #include <getopt.h>
+#include <pthread.h>
+#include <pthread_np.h>
 
 #if defined(__sun)
 #include <sys/processor.h>
@@ -8123,12 +8127,17 @@ real_setup(unsigned int  cpu,
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
+	  status = cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID,
+	    -1, sizeof(cpuset_t), &cpuset);
+#else
+         status = sched_setaffinity(0, sizeof(cpuset_t), &cpuset);
 #endif
+#endif
          if (status == -1) {
             if (cpu > 0) {
                if (errno == EINVAL) return -1;
@@ -8250,11 +8259,14 @@ static int real_get (int           cpuid_fd,
             "c" (ecx));
 #endif
    } else {
-      off64_t  result;
-      off64_t  offset = ((off64_t)ecx << 32) + reg;
+      //off64_t  result;
+      //off64_t  offset = ((uint64_t)ecx << 32) + reg;
+      uint64_t  result;
+      uint64_t  offset = ((uint64_t)ecx << 32) + reg;
       int      status;
 
-      result = lseek64(cpuid_fd, offset, SEEK_SET);
+      //result = lseek64(cpuid_fd, offset, SEEK_SET);
+      result = lseek(cpuid_fd, offset, SEEK_SET);
       if (result == -1) {
          if (quiet) {
             return FALSE;
@@ -8819,7 +8831,7 @@ main(int     argc,
    };
 
    boolean        opt_one_cpu     = FALSE;
-   boolean        opt_inst        = FALSE;
+   boolean        opt_inst        = TRUE;
    boolean        opt_kernel      = FALSE;
    boolean        opt_raw         = FALSE;
    boolean        opt_debug       = FALSE;
@@ -8950,7 +8962,8 @@ main(int     argc,
    }
 
    // Default to -i.  So use inst unless -k is specified.
-   boolean  inst = !opt_kernel;
+   //boolean  inst = !opt_kernel;
+   boolean  inst = TRUE;
 
    if (opt_version) {
       printf("cpuid version %s\n", XSTR(VERSION));
