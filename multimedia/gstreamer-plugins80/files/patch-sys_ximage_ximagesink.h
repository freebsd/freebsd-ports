--- sys/ximage/ximagesink.h.orig	Tue Mar 16 22:51:03 2004
+++ sys/ximage/ximagesink.h	Tue Mar 16 23:06:44 2004
@@ -23,6 +23,7 @@
 #include <gst/video/videosink.h>
 
 #ifdef HAVE_XSHM
+#include <sys/types.h>
 #include <sys/ipc.h>
 #include <sys/shm.h>
 #endif /* HAVE_XSHM */
