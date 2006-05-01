--- src/gt-util.c.orig	Mon May  1 20:00:48 2006
+++ src/gt-util.c	Mon May  1 20:01:35 2006
@@ -53,8 +53,7 @@
 				GTK_MESSAGE_ERROR,
 				GTK_BUTTONS_OK,
 				primary,
-				secondary,
-				NULL);
+				secondary);
 
   if (blocking)
     {
