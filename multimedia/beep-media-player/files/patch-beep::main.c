--- beep/main.c.orig	Fri Nov 14 05:29:27 2003
+++ beep/main.c	Fri Nov 14 05:30:06 2003
@@ -2030,11 +2030,12 @@
 		
 
 		if (!strncasecmp(path,"fonts:///",9)) {
+				gchar * decoded;
 				path[strlen(path)-2] = 0; /* Why the hell a CR&LF? */
 				path = path + 8;
 
 				/* plain, since we already stripped the first URI part */
-				gchar * decoded = xmms_urldecode_plain(path);
+				decoded = xmms_urldecode_plain(path);
 				decoded++;
 
 				/* Get the old font's size, and add it to the dropped font's name */
