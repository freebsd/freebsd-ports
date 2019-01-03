--- src/gholder.c.orig	2018-12-16 00:54:24 UTC
+++ src/gholder.c
@@ -34,6 +34,7 @@
 #include <string.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
+#include <sys/socket.h>
 
 #ifdef HAVE_LIBTOKYOCABINET
 #include "tcabdb.h"
