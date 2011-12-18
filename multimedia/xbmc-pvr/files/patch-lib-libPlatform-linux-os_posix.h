--- lib/libPlatform/linux/os_posix.h.orig
+++ lib/libPlatform/linux/os_posix.h
@@ -32,7 +32,7 @@
 #include <sys/timeb.h>
 #include <sys/resource.h>
 #include <sys/syscall.h>
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <sys/prctl.h> 
 #endif
 #include <pthread.h>
