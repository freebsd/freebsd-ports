--- src/bytestream-socks5.c.orig	2009-01-08 01:57:01.000000000 -0500
+++ src/bytestream-socks5.c	2009-01-08 01:57:20.000000000 -0500
@@ -21,6 +21,8 @@
 #include "config.h"
 #include "bytestream-socks5.h"
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <arpa/inet.h>
 #include <errno.h>
 #include <fcntl.h>
