--- ../common/network/TcpSocket.cxx.orig	2008-10-16 08:16:20.000000000 -0700
+++ ../common/network/TcpSocket.cxx	2013-10-29 09:29:55.935208477 -0700
@@ -35,6 +35,7 @@
 #include <string.h>
 #include <signal.h>
 #include <fcntl.h>
+#include <stdlib.h>
 #endif
 
 #include <network/TcpSocket.h>
