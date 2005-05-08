--- lib/ipmi_lanp.c.orig	Thu Mar 24 07:39:01 2005
+++ lib/ipmi_lanp.c	Tue Apr  5 09:17:30 2005
@@ -38,11 +38,11 @@
 #include <stdio.h>
 #include <string.h>
 #include <strings.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <errno.h>
-#include <sys/types.h>
 #include <unistd.h>
 #include <signal.h>
 #include <setjmp.h>
