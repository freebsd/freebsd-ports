--- rcfile.y.orig	Tue Dec 18 14:41:08 2001
+++ rcfile.y	Fri Jan 20 21:05:00 2006
@@ -261,11 +261,13 @@
 	| config_options display_real_names_option
 	| config_options show_chat_button_option
 	| config_options show_status_option
+	;
 
 contact_options: /* empty */
 	| contact_options name_option
 	| contact_options event_option
 	| contact_options email_option
+	;
 
 name_option: NAME QSTRING {
 		DBG_Print("rcfile", "[RC] Got contact name (%s)\n", $2);
@@ -286,17 +288,14 @@
     if ( images.status.away ) 
 	    free(images.status.away);
 	images.status.away = strdup($2); } 
-    ;
     | IMAGE_STATUS_IDLE QSTRING { 	
     if ( images.status.idle ) 
 	    free(images.status.idle);
 	images.status.idle = strdup($2); } 
-    ;
     | IMAGE_STATUS_HERE QSTRING { 	
     if ( images.status.here ) 
 	    free(images.status.here);
 	images.status.here = strdup($2); } 
-    ;
     | IMAGE_STATUS_OFFLINE QSTRING { 	
     if ( images.status.offline ) 
 	    free(images.status.offline);
@@ -335,7 +334,6 @@
 			DBG_Print("rcfile", "[RC] Set proxy host to '%s'\n", $2);
 			proxy_host = strdup($2); }
 		}
-	;
 	| PROXY_PORT INTEGER {
 		if (config_match) {
 			proxy_port = $2;
