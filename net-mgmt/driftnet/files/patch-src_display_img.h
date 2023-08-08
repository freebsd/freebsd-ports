--- src/display/img.h.orig	2023-07-15 23:49:00 UTC
+++ src/display/img.h
@@ -69,6 +69,7 @@ typedef uint32_t pel;
 #   define GETB(p)             ((chan)(((p) & (pel)0xff000000) >> 24))
 #   define GETA(p)             ((chan)(((p) & (pel)0x000000ff)      ))
 #endif
+#else
 #   error "no endianness defined"
 #endif
 
