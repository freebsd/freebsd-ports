--- src/utils.c	2024-09-11 02:00:14.000000000 -0700
+++ src/utils.c	2024-09-19 13:33:16.044626000 -0700
@@ -34,7 +34,7 @@
 /**
  * @brief Needed for nanosleep.
  */
-#define _POSIX_C_SOURCE 199309L
+//#define _POSIX_C_SOURCE 199309L
 
 #include "utils.h"
 
@@ -50,6 +50,11 @@
 #include <sys/wait.h>
 #include <unistd.h>
 
+#if defined(__FreeBSD__)
+#include <sys/sysctl.h>
+#include <sys/types.h>
+#endif
+
 #include <gvm/base/gvm_sentry.h>
 
 #undef G_LOG_DOMAIN
@@ -1035,8 +1040,23 @@
 guint64
 phys_mem_available ()
 {
-  return (unsigned long long)(sysconf(_SC_AVPHYS_PAGES))
+  uint64_t retval;
+
+#if defined(__FreeBSD__)
+  uint64_t npages, pagesize;
+  size_t npages_len = sizeof(npages);
+  size_t pagesize_len = sizeof(pagesize);
+
+  sysctlbyname("vm.stats.vm.v_free_count", &npages, &npages_len, NULL, 0);
+  sysctlbyname("vm.stats.vm.v_page_size", &pagesize, &pagesize_len, NULL, 0);
+
+  retval = pagesize * npages;
+#else
+  retval=(unsigned long long)(sysconf(_SC_AVPHYS_PAGES))
     * sysconf(_SC_PAGESIZE);
+#endif
+
+ return retval;
 }
 
 /**
