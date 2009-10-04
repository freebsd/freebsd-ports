--- lives-plugins/plugins/playback/video/lives2lives_stream.c.orig	2009-08-12 05:42:46.000000000 +0900
+++ lives-plugins/plugins/playback/video/lives2lives_stream.c	2009-09-30 00:31:51.000000000 +0900
@@ -41,7 +41,10 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <netdb.h>
+#include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <string.h>
 #include <errno.h>
 
