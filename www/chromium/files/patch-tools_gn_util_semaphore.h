--- tools/gn/util/semaphore.h.orig	2018-12-12 23:06:54.000000000 +0100
+++ tools/gn/util/semaphore.h	2018-12-15 22:00:54.077539000 +0100
@@ -15,7 +15,7 @@
 #include <windows.h>
 #elif defined(OS_MACOSX)
 #include <mach/mach.h>
-#elif defined(OS_LINUX) || defined(OS_AIX)
+#elif defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
 #include <semaphore.h>
 #else
 #error Port.
@@ -35,7 +35,7 @@
 
 #if defined(OS_MACOSX)
   typedef semaphore_t NativeHandle;
-#elif defined(OS_LINUX) || defined(OS_AIX)
+#elif defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
   typedef sem_t NativeHandle;
 #elif defined(OS_WIN)
   typedef HANDLE NativeHandle;
