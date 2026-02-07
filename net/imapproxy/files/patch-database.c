--- database.c.orig	Fri Aug  9 15:24:23 2002
+++ database.c		Mon Jul 28 11:22:10 2003
@@ -24,6 +24,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <errno.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
