
$FreeBSD$

--- coreapi/enum.c.orig	Sat Mar  6 01:21:40 2004
+++ coreapi/enum.c	Thu Apr 15 03:46:41 2004
@@ -21,7 +21,10 @@
 
 #include "enum.h"
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 #include <arpa/nameser.h>
 #include <resolv.h>
 #include <errno.h>
