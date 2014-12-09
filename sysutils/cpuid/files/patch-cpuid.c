--- cpuid.c.orig	2014-01-24 01:26:27 UTC
+++ cpuid.c
@@ -17,6 +17,8 @@
 ** 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
 
+#define CPUID_MAJOR 0
+
 #define _GNU_SOURCE
 #include <stdio.h>
 #include <sys/types.h>
@@ -26,11 +28,14 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <string.h>
-#include <linux/major.h>
+//#include <linux/major.h>
 #include <regex.h>
 #include <getopt.h>
 #include <sys/syscall.h>
 
+#include <pthread.h>
+#include <pthread_np.h>
+
 typedef int   boolean;
 #define TRUE  1
 #define FALSE 0
@@ -5877,7 +5882,8 @@ real_setup(unsigned int  cpu,
             = (1 << cpu % (sizeof(unsigned int)*8));
 
          int  status;
-         status = syscall(__NR_sched_setaffinity, 0, sizeof(mask), &mask);
+         //status = syscall(__NR_sched_setaffinity, 0, sizeof(mask), &mask);
+         status = pthread_setaffinity_np(0, sizeof(mask), &mask);
          if (status == -1) {
             if (cpu > 0) {
                if (errno == EINVAL) return -1;
@@ -5987,11 +5993,14 @@ static int real_get (int           cpuid
           : "a" (reg), 
             "c" (ecx));
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
@@ -6432,7 +6441,8 @@ main(int     argc,
    };
 
    boolean  opt_one_cpu  = FALSE;
-   boolean  opt_inst     = FALSE;
+   //boolean  opt_inst     = FALSE;
+   boolean  opt_inst     = TRUE;
    boolean  opt_kernel   = FALSE;
    boolean  opt_raw      = FALSE;
    boolean  opt_debug    = FALSE;
@@ -6508,7 +6518,8 @@ main(int     argc,
    }
 
    // Default to -i.  So use inst unless -k is specified.
-   boolean  inst = !opt_kernel;
+   //boolean  inst = !opt_kernel;
+   boolean  inst = TRUE;
 
    if (opt_version) {
       printf("cpuid version %s\n", XSTR(VERSION));
