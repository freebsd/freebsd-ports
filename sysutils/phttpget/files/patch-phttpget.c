--- phttpget.c.orig	2015-12-23 13:46:44.780539000 -0800
+++ phttpget.c	2015-12-23 13:47:03.377740000 -0800
@@ -76,7 +76,7 @@
 
 	env_HTTP_USER_AGENT = getenv("HTTP_USER_AGENT");
 	if (env_HTTP_USER_AGENT == NULL)
-		env_HTTP_USER_AGENT = "phttpget/0.1";
+		env_HTTP_USER_AGENT = "phttpget/0.2";
 }
 
 static int
