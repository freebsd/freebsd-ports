--- libannex/slip_layer.c.orig	Thu Aug  4 15:58:46 1994
+++ libannex/slip_layer.c	Thu Sep 18 20:18:34 2003
@@ -70,6 +70,8 @@
 #include "port/port.h"
 #include <sys/stat.h>
 #include <sys/fcntl.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <stdio.h>
 #include <errno.h>
 #include "../inc/slip/slip_user.h"
@@ -101,10 +103,7 @@
  *****************************************************************************/
 
 extern int debug;
-extern errno_t errno;
-
-extern UINT32 inet_addr();
-
+extern int errno;
 
 /*****************************************************************************
  *									     *
