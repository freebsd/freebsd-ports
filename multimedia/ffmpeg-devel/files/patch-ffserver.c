--- ffserver.c.orig	Tue Sep 25 14:53:44 2001
+++ ffserver.c	Tue Sep 25 14:55:12 2001
@@ -20,7 +20,6 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
-#include <netinet/in.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
@@ -31,6 +30,7 @@
 #include <getopt.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netdb.h>
 #include <ctype.h>
