--- rcfile.y.orig	Sun Dec  1 22:51:31 2002
+++ rcfile.y	Sun Dec  1 22:53:42 2002
@@ -253,11 +253,13 @@
 	| config_options idle_time_option
 	| config_options show_notify_messages_option
 	| config_options display_real_names_option
+	;
 
 contact_options: /* empty */
 	| contact_options name_option
 	| contact_options event_option
 	| contact_options email_option
+	;
 
 name_option: NAME QSTRING {
 		DBG_Print("rcfile", "[RC] Got contact name (%s)\n", $2);
@@ -278,17 +280,14 @@
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
@@ -327,7 +326,6 @@
 			DBG_Print("rcfile", "[RC] Set proxy host to '%s'\n", $2);
 			proxy_host = strdup($2); }
 		}
-	;
 	| PROXY_PORT INTEGER {
 		if (config_match) {
 			proxy_port = $2;
