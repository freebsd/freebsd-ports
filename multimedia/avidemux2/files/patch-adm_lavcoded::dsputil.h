--- adm_lavcodec/dsputil.h.orig	Sat Feb 14 16:22:04 2004
+++ adm_lavcodec/dsputil.h	Sat Feb 14 16:22:28 2004
@@ -487,6 +487,7 @@
           +name8(s, dst+8+8*stride, src+8+8*stride, stride);\
 }
 
+#define HAVE_LRINTF
 #ifndef HAVE_LRINTF
 /* XXX: add ISOC specific test to avoid specific BSD testing. */
 /* better than nothing implementation. */
