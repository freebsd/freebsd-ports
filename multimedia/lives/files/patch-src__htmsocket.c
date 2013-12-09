--- ./src/htmsocket.c.orig	2013-11-12 03:18:17.000000000 +0100
+++ ./src/htmsocket.c	2013-12-05 19:12:38.657055983 +0100
@@ -8,7 +8,7 @@
 #include <stdio.h>
 #include <unistd.h>
 #include <errno.h>
-
+#include <netinet/in.h>
 #ifndef IS_MINGW
 #include <netdb.h>
 #include <sys/socket.h>
