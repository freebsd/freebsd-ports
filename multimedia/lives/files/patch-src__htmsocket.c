--- ./src/htmsocket.c.orig	2013-07-03 02:29:02.000000000 +0200
+++ ./src/htmsocket.c	2013-10-27 21:11:48.514119239 +0100
@@ -8,7 +8,7 @@
 #include <stdio.h>
 #include <unistd.h>
 #include <errno.h>
-
+#include <netinet/in.h>
 #ifndef IS_MINGW
 #include <netdb.h>
 #include <sys/socket.h>
