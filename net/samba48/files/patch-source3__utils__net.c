--- source3/utils/net.c.orig	2017-07-04 10:05:26 UTC
+++ source3/utils/net.c
@@ -1087,8 +1087,13 @@ static struct functable net_func[] = {
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
