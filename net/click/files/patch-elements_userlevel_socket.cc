--- elements/userlevel/socket.cc.orig	2006-04-08 16:22:40.000000000 +0000
+++ elements/userlevel/socket.cc
@@ -29,6 +29,7 @@
 #include <arpa/inet.h>
 #include <netinet/tcp.h>
 #include <fcntl.h>
+#include <cstddef>
 #include "socket.hh"
 
 CLICK_DECLS
