--- ccan/ccan/fdpass/fdpass.c.orig	2020-01-20 22:03:36 UTC
+++ ccan/ccan/fdpass/fdpass.c
@@ -1,6 +1,7 @@
 /* CC0 license (public domain) - see LICENSE file for details */
 #include <ccan/fdpass/fdpass.h>
 #include <sys/socket.h>
+#include <sys/types.h>
 #include <errno.h>
 #include <string.h>
 
