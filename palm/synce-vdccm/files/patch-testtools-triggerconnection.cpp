--- tools/triggerconnection.cpp.orig	Fri Jan 26 19:27:52 2007
+++ tools/triggerconnection.cpp	Fri Jan 26 19:28:25 2007
@@ -16,6 +16,7 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 
 
 int main(int argc, char *argv[])
