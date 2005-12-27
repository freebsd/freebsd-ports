--- coreapi/linphonecore.c.orig	Thu Dec  8 02:37:31 2005
+++ coreapi/linphonecore.c	Tue Dec 20 13:24:10 2005
@@ -36,9 +36,7 @@
 #include <arpa/inet.h>
 #include <time.h>
 
-#ifdef INET6  
 #include <netdb.h>  
-#endif
 
 #include "enum.h"
 
@@ -1225,12 +1223,12 @@
 {
     char *real_url=NULL;
     osip_to_t *real_parsed_url=NULL;
+    LinphoneCall *call=lc->call;
     if (!linphone_core_interpret_url(lc,url,&real_url,&real_parsed_url)){
         /* bad url */
         return -1;
     }
 
-    LinphoneCall *call=lc->call;
     if (call==NULL){
         g_warning("No established call to refer.");
         return -1;
