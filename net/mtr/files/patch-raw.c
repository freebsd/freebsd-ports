--- raw.c.orig	Sat Oct 30 13:27:31 2004
+++ raw.c	Sat Oct 30 13:27:39 2004
@@ -22,6 +22,7 @@
 #include <ctype.h>
 #include <stdlib.h>
 #include <stdio.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
