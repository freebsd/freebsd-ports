--- functions/sybase.c.orig	Tue Feb  8 00:54:51 2000
+++ functions/sybase.c	Tue Feb 29 22:01:07 2000
@@ -366,7 +366,7 @@
 				RETURN_FALSE;
 			}
 			/* create the link */
-			if ((sybase.link=dbopen(sybase.login,host))==FAIL) {
+			if ((sybase.link=tdsdbopen(sybase.login,host))==FAIL) {
 				/*php3_error(E_WARNING,"Sybase:  Unable to connect to server:  %s",sybase_error(sybase));*/
 				efree(hashed_details);
 				dbloginfree(sybase.login);
@@ -408,7 +408,7 @@
 #if BROKEN_SYBASE_PCONNECTS
 				log_error("PHP/Sybase:  Persistent link died, trying to reconnect...",php3_rqst->server);
 #endif
-				if ((sybase_ptr->link=dbopen(sybase_ptr->login,host))==FAIL) {
+				if ((sybase_ptr->link=tdsdbopen(sybase_ptr->login,host))==FAIL) {
 #if BROKEN_SYBASE_PCONNECTS
 					log_error("PHP/Sybase:  Unable to reconnect!",php3_rqst->server);
 #endif
@@ -464,7 +464,7 @@
 			RETURN_FALSE;
 		}
 		
-		if ((sybase.link=dbopen(sybase.login,host))==NULL) {
+		if ((sybase.link=tdsdbopen(sybase.login,host))==NULL) {
 			/*php3_error(E_WARNING,"Sybase:  Unable to connect to server:  %s",sybase_error(sybase));*/
 			efree(hashed_details);
 			RETURN_FALSE;
