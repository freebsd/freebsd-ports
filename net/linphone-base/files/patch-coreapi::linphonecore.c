--- coreapi/linphonecore.c.orig	Fri Sep  8 18:16:44 2006
+++ coreapi/linphonecore.c	Tue Sep 12 22:33:19 2006
@@ -29,10 +29,8 @@
 #include "exevents.h"
 
 
-#ifdef INET6  
 #ifndef WIN32
 #include <netdb.h>  
-#endif
 #endif
 
 #include "enum.h"
