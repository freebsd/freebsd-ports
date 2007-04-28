--- coreapi/linphonecore.c.orig	Thu Apr  5 00:19:40 2007
+++ coreapi/linphonecore.c	Fri Apr 13 01:43:09 2007
@@ -29,11 +29,9 @@
 #include "exevents.h"
 
 
-#ifdef INET6  
 #ifndef WIN32
 #include <netdb.h>  
 #endif
-#endif
 
 
 static const char *liblinphone_version=LIBLINPHONE_VERSION;
