--- src/lm-util.c.orig	Mon May  1 20:09:04 2006
+++ src/lm-util.c	Mon May  1 20:09:10 2006
@@ -273,8 +273,7 @@
 				GTK_MESSAGE_ERROR,
 				GTK_BUTTONS_OK,
 				primary,
-				secondary,
-				NULL);
+				secondary);
 
   if (blocking)
     {
