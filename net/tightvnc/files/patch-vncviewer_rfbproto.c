--- vncviewer/rfbproto.c.orig	2006-12-08 07:20:03 UTC
+++ vncviewer/rfbproto.c
@@ -569,7 +569,7 @@ AuthenticateVNC(void)
     passwd = getpass("Password: ");
   }
 
-  if (!passwd || strlen(passwd) == 0) {
+  if (!passwd) {
     fprintf(stderr, "Reading password failed\n");
     return False;
   }
