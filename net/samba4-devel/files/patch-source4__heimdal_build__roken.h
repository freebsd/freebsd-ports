--- ./source4/heimdal_build/roken.h.orig	2010-01-11 05:35:28.000000000 +0000
+++ ./source4/heimdal_build/roken.h	2010-01-24 21:49:26.000000000 +0000
@@ -49,6 +49,10 @@
 #define HAVE_STRNDUP
 #endif
 
+#ifndef HAVE_STRNLEN
+#define HAVE_STRNLEN
+#endif
+
 #ifndef HAVE_STRLCPY
 #define HAVE_STRLCPY
 #endif
