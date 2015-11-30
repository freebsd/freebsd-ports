--- ./source3/utils/net.c.orig	2013-01-29 08:49:31.000000000 +0000
+++ ./source3/utils/net.c	2013-01-31 15:04:24.069877314 +0000
@@ -898,8 +898,13 @@
 		set_global_myname(c->opt_requester_name);
 	}
 
-	if (!c->opt_user_name && getenv("LOGNAME")) {
-		c->opt_user_name = getenv("LOGNAME");
+	if (!c->opt_user_name) {
+		if(getenv("LOGNAME"))
+			c->opt_user_name = getenv("LOGNAME");
+		else
+			d_fprintf(stderr,
+				_("Environment LOGNAME is not defined."
+			          " Trying anonymous access.\n"));
 	}
 
 	if (!c->opt_workgroup) {
