--- lib/fdbuf/fdbuf.h.orig	Mon Feb  2 14:40:11 2004
+++ lib/fdbuf/fdbuf.h	Mon Feb  2 14:40:38 2004
@@ -25,6 +25,9 @@
 #include <pthread.h>
 #endif
 
+#include <unistd.h>
+#include <sys/types.h>
+
 #ifndef FDBUF_SIZE
 #define FDBUF_SIZE 4096
 #endif
