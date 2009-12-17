--- daemon/keyrings/gkr-keyrings.c.orig	2009-12-16 23:41:18.000000000 -0500
+++ daemon/keyrings/gkr-keyrings.c	2009-12-16 23:41:38.000000000 -0500
@@ -38,6 +38,7 @@
 #include <errno.h>
 #include <stdlib.h>
 #include <stdio.h>
+#include <string.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/un.h>
