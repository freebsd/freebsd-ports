--- src/client.c	Mon Nov  9 23:08:47 1998
+++ src/client.c	Tue Jan 18 15:47:15 2005
@@ -762,5 +762,5 @@
 	char *owner = NULL, *group = NULL;
 	int done, n;
-	u_char *cp;
+	char *cp;
 
 	debugmsg(DM_CALL, "update(%s, 0x%x, 0x%x)\n", rname, opts, statp);
