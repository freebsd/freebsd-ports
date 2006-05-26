--- coreapi/linphonecore.c.orig	Sat Mar 11 00:19:17 2006
+++ coreapi/linphonecore.c	Sat Apr  1 00:57:53 2006
@@ -36,9 +36,7 @@
 #include <arpa/inet.h>
 #include <time.h>
 
-#ifdef INET6  
 #include <netdb.h>  
-#endif
 
 #include "enum.h"
 
