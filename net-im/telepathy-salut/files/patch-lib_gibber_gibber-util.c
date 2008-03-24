--- lib/gibber/gibber-util.c.orig	2008-01-17 00:59:24.000000000 -0500
+++ lib/gibber/gibber-util.c	2008-01-17 00:59:48.000000000 -0500
@@ -18,6 +18,8 @@
  */
 
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <stdio.h>
 #include <unistd.h>
 #include <stdlib.h>
