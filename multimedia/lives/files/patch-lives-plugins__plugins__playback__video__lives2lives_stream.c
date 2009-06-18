--- lives-plugins/plugins/playback/video/lives2lives_stream.c.orig	2008-07-29 16:13:33.000000000 +0900
+++ lives-plugins/plugins/playback/video/lives2lives_stream.c	2009-06-03 01:03:03.000000000 +0900
@@ -8,6 +8,11 @@
 
 #include "videoplugin.h"
 
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
+
 
 //////////////////////////////////////
 
