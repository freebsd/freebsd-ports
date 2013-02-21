diff -Nur src/undo.c src/undo.c
--- src/undo.c	2013-02-19 23:54:34.000000000 +0200
+++ src/undo.c	2013-02-19 23:50:31.000000000 +0200
@@ -17,7 +17,13 @@
 
 #include <config.h>
 #include <assert.h>
+
+#if HAVE_ENDIAN_H
 #include <endian.h>
+#elif HAVE_SYS_ENDIAN_H
+#include <sys/endian.h>
+#endif
+
 #include <errno.h>
 #include <error.h>
 #include <fcntl.h>
