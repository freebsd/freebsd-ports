--- coreapi/linphonecore.c.orig	Thu Mar 17 01:16:55 2005
+++ coreapi/linphonecore.c	Wed Mar 23 13:17:30 2005
@@ -34,9 +34,7 @@
 #include <arpa/inet.h>
 #include <time.h>
 
-#ifdef INET6  
 #include <netdb.h>  
-#endif
 
 #include "enum.h"
 
