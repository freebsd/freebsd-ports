--- ./heimdal_build/config.h.orig	2009-01-19 03:15:19.000000000 +0000
+++ ./heimdal_build/config.h	2009-01-19 04:55:23.000000000 +0000
@@ -58,6 +58,16 @@
 #define OPENLOG_PROTO_COMPATIBLE
 #define GETSOCKNAME_PROTO_COMPATIBLE
 
+#ifndef HAVE_GETPROGNAME
+#define HAVE_GETPROGNAME
+#endif
+#ifndef HAVE_SETPROGNAME
+#define HAVE_SETPROGNAME
+#endif
+#ifndef HAVE___PROGNAME
+#define HAVE___PROGNAME
+#endif
+
 #ifndef HAVE_SOCKLEN_T
 #define HAVE_SOCKLEN_T
 #endif
