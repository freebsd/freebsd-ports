diff -ruw src/common.h src/common.h
--- src/common.h	2004-03-11 08:30:54.000000000 +0100
+++ src/common.h	2004-03-18 13:47:21.000000000 +0100
@@ -212,6 +212,9 @@
     (((x)&0x00ff)<<8))
 #define be16(x)  (x)
 #define be24(x)  (x)
+#define le24(x) ((((x) & 0x000000ffUL) << 16) | \
+    ((x) & 0x0000ff00UL)        | \
+    (((x) & 0x00ff0000UL) >> 16))
 #define le32(x)  ((((x)&0xff000000L)>>24)                | \
     (((x)&0x00ff0000L)>>8)                  | \
     (((x)&0x0000ff00L)<<8)                  | \
