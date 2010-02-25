--- modules/core/src/c/getmemory.c.orig	2009-12-16 07:24:40.000000000 +0000
+++ modules/core/src/c/getmemory.c	2010-01-06 19:27:34.939739546 +0000
@@ -25,8 +25,12 @@
 #include <sys/sysctl.h>
 #define ARRAY_SIZE(a) (sizeof (a) / sizeof ((a)[0]))
 #define PAGESHIFT_UNDEF -100
+#elif defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/sysctl.h>
 #endif
 
+
 #include <stdio.h>
 #define kooctet 1024
 int getfreememory(void)
@@ -160,6 +164,12 @@
 
     return 0;
   }
+#elif defined(__FreeBSD__)
+  int avphys_pages;
+  size_t oldlenp = sizeof (avphys_pages);
+  sysctlbyname("vm.stats.vm.v_free_count", &avphys_pages, &oldlenp, NULL, NULL);
+  return (avphys_pages / kooctet) * sysconf(_SC_PAGESIZE); 
+
 #else
   /* Solaris and others assumed*/
   return (sysconf(_SC_AVPHYS_PAGES)/kooctet)*sysconf(_SC_PAGESIZE);
