--- libs/gcu/application.cc.orig	2013-04-22 13:49:38.000000000 +0000
+++ libs/gcu/application.cc	2013-04-22 13:49:53.000000000 +0000
@@ -39,6 +39,7 @@
 #include <cstring>
 #include <clocale>
 #include <netinet/in.h>
+#include <sys/socket.h>
 #include <sys/un.h>
 #include <unistd.h>
 #include <set>
