$FreeBSD$

--- src/powerman.c.orig	Sun Nov 30 16:13:28 2003
+++ src/powerman.c	Thu Jun 17 09:11:40 2004
@@ -34,6 +34,8 @@
 #include <stdlib.h>
 #include <assert.h>
 #include <libgen.h>
+#include <limits.h>
+#include <sys/socket.h>
 
 #include "powerman.h"
 #include "wrappers.h"
@@ -78,6 +80,24 @@
 };
 
 static const struct option *longopts = long_options;
+
+#ifdef __FreeBSD__
+#include <stdarg.h>
+
+#define BUF_MAX 1024
+
+static int dprintf(int fd, char *const fmt, ...)
+{
+    int ret;
+    va_list ap;
+    char buf[BUF_MAX];
+
+    va_start(ap, fmt);
+    ret = vsnprintf(buf, BUF_MAX, fmt, ap);
+    va_end(ap);
+    return (int) write(fd, buf, (ret > BUF_MAX) ? BUF_MAX : ret);
+}
+#endif
 
 int main(int argc, char **argv)
 {
