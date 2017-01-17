--- src/display/img.h.orig	2013-05-12 15:22:44 UTC
+++ src/display/img.h
@@ -19,11 +19,13 @@
 
 #include <stdio.h>
 
+#include <sys/endian.h>
+
 typedef uint8_t chan;
 typedef uint32_t pel;
 
 /* Yuk. GDKRGB expects data in a specific ordering. */
-#if defined(DRIFTNET_LITTLE_ENDIAN)
+#if defined(LITTLE_ENDIAN)
 #   define PEL(r, g, b)        ((pel)((chan)(r) | ((chan)(g) << 8) | ((chan)(b) << 16)))
 #   define PELA(r, g, b, a)    ((pel)((chan)(r) | ((chan)(g) << 8) | ((chan)(b) << 16) | ((chan)(a) << 24)))
 
@@ -31,7 +33,7 @@ typedef uint32_t pel;
 #   define GETG(p)             ((chan)(((p) & (pel)0x0000ff00) >>  8))
 #   define GETB(p)             ((chan)(((p) & (pel)0x00ff0000) >> 16))
 #   define GETA(p)             ((chan)(((p) & (pel)0xff000000) >> 24))
-#elif defined(DRIFTNET_BIG_ENDIAN)
+#elif defined(BIG_ENDIAN)
 #   define PEL(r, g, b)        ((pel)(((chan)(r) << 24) | ((chan)(g) << 16) | ((chan)(b) << 8)))
 #   define PELA(r, g, b, a)    ((pel)(((chan)(r) << 24) | ((chan)(g) << 16) | ((chan)(b) << 8) | ((chan)(a))))
 
