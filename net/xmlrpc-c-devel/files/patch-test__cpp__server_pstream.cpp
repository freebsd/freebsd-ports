--- test/cpp/server_pstream.cpp.orig	2011-07-04 14:44:22.000000000 -0300
+++ test/cpp/server_pstream.cpp	2011-07-04 14:44:09.000000000 -0300
@@ -14,6 +14,7 @@
   #include <unistd.h>
   #include <sys/socket.h>
   #include <arpa/inet.h>
+  #include <netinet/in.h>
 #endif
 
 #include <errno.h>
