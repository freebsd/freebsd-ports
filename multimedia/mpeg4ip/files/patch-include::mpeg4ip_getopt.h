--- include/mpeg4ip_getopt.h.orig	Tue Oct 15 13:12:27 2002
+++ include/mpeg4ip_getopt.h	Mon Feb 24 05:23:50 2003
@@ -11,6 +11,9 @@
 #endif
 
 #ifdef HAVE_GETOPT_H
+#ifdef __FreeBSD__
+#define __GNU_LIBRARY__
+#endif
 #include <getopt.h>
 #endif
 
