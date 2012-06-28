--- gst/audioresample/resample.c.orig	2012-06-28 10:15:58.000000000 +0200
+++ gst/audioresample/resample.c	2012-06-28 10:22:41.000000000 +0200
@@ -79,6 +79,9 @@
 #ifdef _USE_SSE
 #ifndef HAVE_XMMINTRIN_H
 #undef _USE_SSE
+/* this is a hack to build on i386, there the configure check for emmintrin.h
+   doesn't fail but the xmmintrin.h does. */
+#undef _USE_SSE2
 #endif
 #endif
 
