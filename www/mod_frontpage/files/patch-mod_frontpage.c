--- mod_frontpage.c	Tue Feb  5 13:56:31 2002
+++ mod_frontpage.c	Tue Feb  5 18:01:27 2002
@@ -124,7 +124,7 @@
 			    "FrontPage disabled for server %s:%d\n",
 			    s->server_hostname, s->port);
 		/*
-		 * As default, enable the mod_frontpage cgi administration
+		 * As default, disable the mod_frontpage cgi administration
 		 */
 		if (c->admindisabled == -1)
 			c->admindisabled = TRUE;
