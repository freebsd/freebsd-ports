--- webredirect.cc.orig Fri Sep 12 00:55:12 2003
+++ webredirect.cc      Fri Sep 12 01:04:57 2003
@@ -7,6 +7,7 @@
 #include <iostream>
 #include <stdexcept>
 #include <map>
+#include <memory>
 #include <incu/error.hh>
 #include <incu/log.hh>
 #include <incu/socket.hh>
@@ -62,7 +62,7 @@
 
 int checked_accept(int serv_sock) {
   struct sockaddr_in remote;
-  size_t len = sizeof(remote);
+  socklen_t len = sizeof(remote);
   
   int remote_fd = accept(serv_sock, reinterpret_cast<sockaddr*>(&remote),
                         &len);
