--- ksirc/puke/controller.cpp.orig	Sat Nov 17 09:54:46 2001
+++ ksirc/puke/controller.cpp	Sat Nov 17 09:55:03 2001
@@ -81,7 +81,7 @@
   unix_addr.sun_family = AF_UNIX;
   strcpy(unix_addr.sun_path, qsPukeSocket);
   len = sizeof(unix_addr.sun_family) + qsPukeSocket.length();
-  if( bind(iListenFd, (struct sockaddr *) &unix_addr, len) < 0){
+  if( bind(iListenFd, (struct sockaddr *) &unix_addr, len + 1) < 0){
     perror("PUKE: Could not bind to Unix Domain Socket");
     return;
   }
