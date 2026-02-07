--- lib/dns-resolve.c.orig	2019-10-18 14:20:09 UTC
+++ lib/dns-resolve.c
@@ -22,6 +22,7 @@
 #include <arpa/nameser.h>
 #include <errno.h>
 #include <string.h>
+#include <sys/socket.h>
 #include <sys/stat.h>
 #include <unbound.h>
 #include "hash.h"
