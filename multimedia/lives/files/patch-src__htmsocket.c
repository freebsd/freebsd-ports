--- ./src/htmsocket.c.orig	2012-06-25 19:47:03.000000000 +0200
+++ ./src/htmsocket.c	2012-06-25 19:48:09.000000000 +0200
@@ -8,7 +8,7 @@
 #include <stdio.h>
 #include <unistd.h>
 #include <errno.h>
-
+#include <netinet/in.h>
 #ifndef IS_MINGW
 #include <netdb.h>
 #include <sys/socket.h>
