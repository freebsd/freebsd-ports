--- wmpiki.c.orig	Thu Feb 19 23:58:54 2004
+++ wmpiki.c	Fri Feb 20 00:05:01 2004
@@ -118,9 +118,9 @@
 int  ret;
 
 	strcpy(commandbuffer, "ping ");
-	strcat(commandbuffer, hostname);
-	strcat(commandbuffer, " ");
 	strcat(commandbuffer, ping_options);
+	strcat(commandbuffer, " ");
+	strcat(commandbuffer, hostname);
 	strcat(commandbuffer, " | grep '");
 	strcat(commandbuffer, ping_grep);
 	strcat(commandbuffer, "'");
