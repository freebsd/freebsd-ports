--- editors/vi.c.orig	2008-11-09 17:28:21.000000000 +0000
+++ editors/vi.c	2010-12-15 20:27:20.000000000 +0000
@@ -383,6 +383,31 @@
 static int crashme = 0;
 #endif
 
+/* Test for existance of memrchr() */
+
+#include <sys/param.h>
+#if (__FreeBSD_version < 603103) || (__FreeBSD_version < 700109 && __FreeBSD_version >= 700000) || (__FreeBSD_version < 800034 && __FreeBSD_version >=800000)
+static void *
+memrchr(const void *buf, int c, size_t num)
+{
+       unsigned char *pMem = (unsigned char *) buf;
+
+       for (;;) {
+               if (num-- == 0) {
+                       return NULL;
+               }
+
+               if (*pMem-- == (unsigned char) c) {
+                       break;
+               }
+
+       }
+
+       return (void *) (pMem + 1);
+
+}
+#endif
+
 
 static void write1(const char *out)
 {
