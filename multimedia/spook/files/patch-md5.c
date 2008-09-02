--- md5.c.orig	2008-09-02 14:40:15.000000000 +0100
+++ md5.c	2008-09-02 14:41:52.000000000 +0100
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
