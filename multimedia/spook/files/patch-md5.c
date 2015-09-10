--- md5.c.orig	2004-12-09 18:09:09 UTC
+++ md5.c
@@ -21,7 +21,11 @@
 #include <string.h>
 #include <sys/types.h>
 
+#ifdef __FreeBSD__
+#include <machine/endian.h>
+#else
 #include <endian.h>
+#endif
 #if __BYTE_ORDER == __BIG_ENDIAN
 #define WORDS_BIGENDIAN
 #endif
