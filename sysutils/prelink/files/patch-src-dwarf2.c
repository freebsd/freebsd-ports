diff -Nur src/dwarf2.c src/dwarf2.c
--- src/dwarf2.c	2013-02-19 23:54:34.000000000 +0200
+++ src/dwarf2.c	2013-02-19 23:50:31.000000000 +0200
@@ -17,8 +17,20 @@
 
 #include <config.h>
 #include <assert.h>
+
+#if HAVE_BYTESWAP_H
 #include <byteswap.h>
+#elif HAVE_SYS_ENDIAN_H
+#include <sys/endian.h>
+#define bswap_32 bswap32
+#endif
+
+#if HAVE_ENDIAN_H
 #include <endian.h>
+#elif HAVE_SYS_ENDIAN_H
+#include <sys/endian.h>
+#endif
+
 #include <errno.h>
 #include <error.h>
 #include <limits.h>
