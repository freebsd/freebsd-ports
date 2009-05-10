--- coreapi/linphonecore.c.orig	2009-03-10 00:22:47.000000000 +0900
+++ coreapi/linphonecore.c	2009-03-26 01:38:40.000000000 +0900
@@ -29,11 +29,9 @@
 #include "exevents.h"
 
 
-#ifdef INET6  
 #ifndef WIN32
 #include <netdb.h>  
 #endif
-#endif
 
 #ifdef WIN32
 #define HAVE_EXOSIP_GET_VERSION 1
@@ -341,7 +339,7 @@
 	const char **devices;
 	int ndev;
 	int i;
-#ifndef WIN32
+#ifdef __linux
 	/*alsadev let the user use custom alsa device within linphone*/
 	devid=lp_config_get_string(lc->config,"sound","alsadev",NULL);
 	if (devid){
