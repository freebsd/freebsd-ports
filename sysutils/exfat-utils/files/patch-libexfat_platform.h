--- libexfat/platform.h.orig	2016-06-03 05:30:35 UTC
+++ libexfat/platform.h
@@ -46,7 +46,7 @@
 #define EXFAT_LITTLE_ENDIAN LITTLE_ENDIAN
 #define EXFAT_BIG_ENDIAN BIG_ENDIAN
 
-#elif defined(__FreeBSD__) || defined(__DragonFlyBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
 
 #include <sys/endian.h>
 #define exfat_bswap16(x) bswap16(x)
