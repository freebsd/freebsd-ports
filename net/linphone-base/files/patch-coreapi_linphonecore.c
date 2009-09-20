--- coreapi/linphonecore.c.orig	2009-09-19 13:56:58.000000000 -0300
+++ coreapi/linphonecore.c	2009-09-19 13:58:01.000000000 -0300
@@ -31,11 +31,9 @@
 #include "exevents.h"
 
 
-#ifdef INET6  
 #ifndef WIN32
 #include <netdb.h>  
 #endif
-#endif
 
 #ifdef WIN32
 #define HAVE_EXOSIP_GET_VERSION 1
