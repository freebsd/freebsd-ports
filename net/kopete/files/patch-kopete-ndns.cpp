--- kopete/protocols/jabber/libpsi/src/ndns.cpp.orig	Tue Nov  5 16:26:22 2002
+++ kopete/protocols/jabber/libpsi/src/ndns.cpp	Tue Nov  5 16:26:51 2002
@@ -52,8 +52,8 @@
 
 #ifdef Q_OS_UNIX
 #include<netdb.h>
-#include<netinet/in.h>
 #include<arpa/inet.h>
+#include<netinet/in.h>
 #include<sys/types.h>
 #endif
 
