--- src/remote.c.orig	2007-11-12 12:09:03.000000000 +0900
+++ src/remote.c	2012-10-21 04:50:16.000000000 +0900
@@ -36,7 +36,7 @@
 remove_fifos(gpointer data)
 {
   // if not even enabled manually, just go away
-  if (pref.rem_mode != REMOTE_SOCK) return;
+  if (pref.rem_mode != REMOTE_SOCK) return FALSE;
   
 printf("Removing the remote pipes\n");
   close(pref.inpipe);
