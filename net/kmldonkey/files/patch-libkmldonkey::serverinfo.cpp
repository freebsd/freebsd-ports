--- libkmldonkey/serverinfo.cpp.orig	Sat Mar  1 18:00:26 2003
+++ libkmldonkey/serverinfo.cpp	Sat Mar  1 18:00:33 2003
@@ -20,6 +20,7 @@
  * $Log$
  */
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
