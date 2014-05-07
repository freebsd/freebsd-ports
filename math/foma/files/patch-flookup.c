--- flookup.c.orig	2014-05-07 17:56:43.000000000 +0400
+++ flookup.c	2014-05-07 17:57:05.000000000 +0400
@@ -23,6 +23,7 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include "fomalib.h"
 
