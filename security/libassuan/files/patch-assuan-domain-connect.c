--- src/assuan-domain-connect.c.orig	Fri Feb 13 14:41:34 2004
+++ src/assuan-domain-connect.c	Mon Apr 19 15:29:50 2004
@@ -26,12 +26,14 @@
 #include <stddef.h>
 #include <stdio.h>
 #include <errno.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <string.h>
 #include <assert.h>
+#include <isc/eventlib.h>
 
 #include "assuan-defs.h"
 
