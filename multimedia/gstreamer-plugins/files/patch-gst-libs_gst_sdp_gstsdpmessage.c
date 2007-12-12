--- gst-libs/gst/sdp/gstsdpmessage.c.orig	2007-12-02 11:51:45.000000000 -0500
+++ gst-libs/gst/sdp/gstsdpmessage.c	2007-12-02 11:52:01.000000000 -0500
@@ -64,7 +64,7 @@
 #ifdef HAVE_SYS_TYPES_H
 #include <sys/types.h>
 #endif
-
+#include <netinet/in.h>
 #include <glib.h>               /* for G_OS_WIN32 */
 
 #ifdef G_OS_WIN32
