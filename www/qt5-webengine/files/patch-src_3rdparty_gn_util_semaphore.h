--- src/3rdparty/gn/util/semaphore.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/gn/util/semaphore.h
@@ -15,7 +15,7 @@
 #include <windows.h>
 #elif defined(OS_MACOSX)
 #include <mach/mach.h>
-#elif defined(OS_LINUX) || defined(OS_AIX)
+#elif defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
 #include <semaphore.h>
 #else
 #error Port.
@@ -35,7 +35,7 @@ class Semaphore {
 
 #if defined(OS_MACOSX)
   typedef semaphore_t NativeHandle;
-#elif defined(OS_LINUX) || defined(OS_AIX)
+#elif defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
   typedef sem_t NativeHandle;
 #elif defined(OS_WIN)
   typedef HANDLE NativeHandle;
