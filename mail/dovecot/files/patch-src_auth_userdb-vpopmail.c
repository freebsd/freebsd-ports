--- src/auth/userdb-vpopmail.c.orig	Thu Mar 15 08:13:18 2007
+++ src/auth/userdb-vpopmail.c	Thu Mar 15 08:13:28 2007
@@ -27,7 +27,7 @@
 		return NULL;
 	}
 
-	auth_request_log_debug(auth_request, "vpopmail",
+	auth_request_log_debug(request, "vpopmail",
 			       "lookup user=%s domain=%s",
 			       vpop_user, vpop_domain);
 
