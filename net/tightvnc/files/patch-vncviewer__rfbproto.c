--- vncviewer/rfbproto.c~	2006-12-08 18:20:03.000000000 +1100
+++ vncviewer/rfbproto.c	2013-09-29 09:19:34.782746129 +1000
@@ -569,7 +569,7 @@
     passwd = getpass("Password: ");
   }
 
-  if (!passwd || strlen(passwd) == 0) {
+  if (!passwd) {
     fprintf(stderr, "Reading password failed\n");
     return False;
   }

