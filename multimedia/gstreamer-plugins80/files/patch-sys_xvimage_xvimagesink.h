--- sys/xvimage/xvimagesink.h.orig	Tue Mar 16 22:51:04 2004
+++ sys/xvimage/xvimagesink.h	Tue Mar 16 23:07:39 2004
@@ -23,6 +23,7 @@
 #include <gst/video/videosink.h>
 
 #ifdef HAVE_XSHM
+#include <sys/types.h>
 #include <sys/ipc.h>
 #include <sys/shm.h>
 #endif /* HAVE_XSHM */
