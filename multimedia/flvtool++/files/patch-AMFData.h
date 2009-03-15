--- AMFData.h.orig	2009-01-22 09:09:49.000000000 +0800
+++ AMFData.h	2009-03-15 01:52:25.000000000 +0800
@@ -18,7 +18,7 @@
   #include <architecture/byte_order.h>
   #define hton64(x) OSSwapHostToBigInt64(x)
 #else
-  #include <byteswap.h>
+  #include <sys/endian.h>
   #if __BYTE_ORDER == __LITTLE_ENDIAN
     #define hton64(x) bswap_64(x)
   #else
