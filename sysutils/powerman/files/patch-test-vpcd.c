$FreeBSD$

--- test/vpcd.c.orig	Mon Dec  1 01:16:33 2003
+++ test/vpcd.c	Thu Jun 17 09:38:30 2004
@@ -16,6 +16,8 @@
 #include <getopt.h>
 #include <unistd.h>
 #include <stdlib.h>
+#include <sys/types.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <sys/types.h>
 #include <sys/socket.h>
@@ -49,6 +51,24 @@
 
 static int errcount = 0;
 
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
+
 static void _noop_handler(int signum)
 {
     fprintf(stderr, "vpcd: received signal %d\n", signum);
@@ -392,7 +412,7 @@
         case 'n':              /* --num_threads n */
             num_threads = strtol(optarg, NULL, 0);
             if (num_threads < MIN_THREADS || num_threads > MAX_THREADS) {
-                fprintf(stderr, "num_threads value out of range (%d-%d)\n",
+                fprintf(stderr, "num_threads value out of range (%d-%ld)\n",
                         MIN_THREADS, MAX_THREADS);
                 exit(1);
             }
