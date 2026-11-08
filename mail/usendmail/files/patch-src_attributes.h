--- src/attributes.h.orig	2003-04-24 07:07:23 UTC
+++ src/attributes.h
@@ -71,7 +71,7 @@
 
 #define attribute_inline __inline__
 
-#if GNUC_MINIMUM(2,7) /* doesn't work reliable before, IIRC */
+#if GNUC_MINIMUM(2,7) && (defined(__i386__) || defined(__x86_64__)) /* doesn't work reliable before, IIRC */
 # define attribute_regparm(x) __attribute__((__regparm__((x))))
 #else
 # define attribute_regparm(x)
