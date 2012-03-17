--- lib/platform/posix/os-types.h.orig
+++ lib/platform/posix/os-types.h
@@ -35,7 +35,7 @@
 #include <string.h>
 #include <errno.h>
 #include <sys/time.h>
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <sys/prctl.h>
 #endif
 #include <pthread.h>
