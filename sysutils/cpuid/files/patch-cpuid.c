--- cpuid.c.orig	2018-04-19 14:15:07 UTC
+++ cpuid.c
@@ -21,17 +21,19 @@
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
 #define _GNU_SOURCE
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <sys/sysmacros.h>
 #include <fcntl.h>
 #include <errno.h>
 #include <unistd.h>
@@ -39,6 +41,8 @@
 #include <string.h>
 #include <regex.h>
 #include <getopt.h>
+#include <pthread.h>
+#include <pthread_np.h>
 
 #ifdef USE_CPUID_MODULE
 #include <linux/major.h>
@@ -67,6 +71,7 @@ typedef const char* const  ccstring;
 #define XSTR(x)  STR(x)
 
 
+#undef MAX
 #define MAX(l,r)            ((l) > (r) ? (l) : (r))
 
 #define LENGTH(array, type) (sizeof(array) / sizeof(type))
@@ -6622,11 +6627,16 @@ real_setup(unsigned int  cpu,
          int  status;
          status = syscall(__NR_sched_setaffinity, 0, sizeof(mask), &mask);
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
+#endif
 #endif
          if (status == -1) {
             if (cpu > 0) {
@@ -6749,11 +6759,14 @@ static int real_get (int           cpuid
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
@@ -7307,7 +7320,7 @@ main(int     argc,
    };
 
    boolean        opt_one_cpu     = FALSE;
-   boolean        opt_inst        = FALSE;
+   boolean        opt_inst        = TRUE;
    boolean        opt_kernel      = FALSE;
    boolean        opt_raw         = FALSE;
    boolean        opt_debug       = FALSE;
@@ -7437,7 +7450,8 @@ main(int     argc,
    }
 
    // Default to -i.  So use inst unless -k is specified.
-   boolean  inst = !opt_kernel;
+   //boolean  inst = !opt_kernel;
+   boolean  inst = TRUE;
 
    if (opt_version) {
       printf("cpuid version %s\n", XSTR(VERSION));
