--- src/IMAuth.cpp.orig	Sat Dec  6 02:39:41 2003
+++ src/IMAuth.cpp	Sat Dec  6 02:39:50 2003
@@ -47,7 +47,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
-#include <alloca.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
