--- src/ndns.cpp.orig	Thu Jul 11 18:49:42 2002
+++ src/ndns.cpp	Thu Jul 11 18:40:24 2002
@@ -51,6 +51,7 @@
 #include "ndns.h"
 
 #ifdef Q_OS_UNIX
+#include	<sys/types.h>
 #include<netdb.h>
 #include<netinet/in.h>
 #include<arpa/inet.h>
