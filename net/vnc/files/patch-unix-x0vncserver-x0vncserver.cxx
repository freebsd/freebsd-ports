--- x0vncserver/x0vncserver.cxx.old	Sat Sep 22 17:03:21 2007
+++ x0vncserver/x0vncserver.cxx	Sat Sep 22 17:03:43 2007
@@ -297,7 +297,7 @@
     vlog.info("Listening on port %d", (int)rfbport);
 
     while (true) {
-      struct timeval tv;
+      struct timeval tv = {0, 0};
       struct timeval* tvp = 0;
       fd_set rfds;
       std::list<Socket*> sockets;
