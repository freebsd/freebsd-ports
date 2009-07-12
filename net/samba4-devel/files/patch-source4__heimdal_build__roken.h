--- ./source4/heimdal_build/roken.h.orig	2009-06-19 04:36:48.000000000 +0000
+++ ./source4/heimdal_build/roken.h	2009-07-12 02:39:36.000000000 +0000
@@ -41,6 +41,10 @@
 #define HAVE_STRNDUP
 #endif
 
+#ifndef HAVE_STRNLEN
+#define HAVE_STRNLEN
+#endif
+
 #ifndef HAVE_STRLCPY
 #define HAVE_STRLCPY
 #endif
