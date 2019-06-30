--- source3/utils/net.c.orig	2019-01-15 10:07:00 UTC
+++ source3/utils/net.c
@@ -1096,8 +1096,13 @@ static void get_credentials_file(struct 
 		lp_set_cmdline("netbios name", c->opt_requester_name);
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
