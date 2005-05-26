--- cherokee/buffer.c.orig	Tue May 24 00:46:59 2005
+++ cherokee/buffer.c	Tue May 24 16:18:01 2005
@@ -39,6 +39,10 @@
 #include "util.h"
 #include "crc32.h"
 
+#ifndef va_copy
+#define va_copy(to,fr) ((to)=(fr))
+#endif
+
 #define BUFFER_VA_LEN 200
 
 #define TO_HEX(c) (c>9? c+'a'-10 : c+'0')
