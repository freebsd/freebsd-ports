--- src/include/platform.h.orig	Sat Nov  5 20:32:56 2005
+++ src/include/platform.h	Sat Nov  5 20:33:19 2005
@@ -57,6 +57,7 @@
  #include <Winsock2.h>
 #else
 #ifndef MINGW
+ #include <sys/types.h>
  #include <netdb.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
