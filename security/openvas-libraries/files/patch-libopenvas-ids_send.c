--- libopenvas/ids_send.c.orig	2008-04-26 23:55:47.000000000 +0900
+++ libopenvas/ids_send.c	2008-04-26 23:56:02.000000000 +0900
@@ -36,6 +36,7 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <arpa/inet.h>
+#include <sys/socket.h>
 
 #include "arglists.h"
 #include "bpf_share.h"
