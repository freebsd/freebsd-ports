--- patricia.c.orig	Tue Oct  7 15:06:56 2003
+++ patricia.c	Tue Oct  7 15:07:19 2003
@@ -52,6 +52,11 @@
 "This product includes software developed by the University of Michigan, Merit"
 "Network, Inc., and their contributors.";
 
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
+
 #include <assert.h> /* assert */
 #include <ctype.h> /* isdigit */
 #include <errno.h> /* errno */
@@ -60,7 +65,6 @@
 #include <stdio.h> /* sprintf, fprintf, stderr */
 #include <stdlib.h> /* free, atol, calloc */
 #include <string.h> /* memcpy, strchr, strlen */
-#include <arpa/inet.h> /* for inet_addr */
 
 #include "patricia.h"
 
