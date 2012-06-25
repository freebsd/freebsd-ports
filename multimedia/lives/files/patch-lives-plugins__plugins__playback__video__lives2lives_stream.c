--- ./lives-plugins/plugins/playback/video/lives2lives_stream.c.orig	2012-06-25 19:50:48.000000000 +0200
+++ ./lives-plugins/plugins/playback/video/lives2lives_stream.c	2012-06-25 19:51:14.000000000 +0200
@@ -8,7 +8,7 @@
 #include <inttypes.h>
 #include <sys/types.h>
 #include <sys/socket.h>
-
+#include <netinet/in.h>
 //////////////////////////////////////
 
 static int palette_list[3];
