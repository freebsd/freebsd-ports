--- src/input/libdvdnav/bswap.h.orig	Wed Apr 30 06:55:46 2003
+++ src/input/libdvdnav/bswap.h	Tue Jul  8 22:28:49 2003
@@ -53,7 +53,7 @@
 #define B2N_32(x) x = swap32(x)
 #define B2N_64(x) x = swap64(x)
 
-#elif defined(__FreeBSD__) && __FreeBSD_version >= 470000
+#elif defined(__FreeBSD__) && __FreeBSD_version >= 500034
 #include <sys/endian.h>
 #define B2N_16(x) x = be16toh(x)
 #define B2N_32(x) x = be32toh(x)
