diff -Nur src/sha.c src/sha.c
--- src/sha.c	2013-02-19 23:54:34.000000000 +0200
+++ src/sha.c	2013-02-19 23:50:31.000000000 +0200
@@ -11,7 +11,14 @@
 #include <sys/types.h>
 #include <stdlib.h>
 #include <string.h>
+
+#if HAVE_BYTESWAP_H
 #include <byteswap.h>
+#elif HAVE_SYS_ENDIAN_H
+#include <sys/endian.h>
+#define bswap_32 bswap32
+#endif
+
 #include "md5.h"
 #include "sha.h"
 
