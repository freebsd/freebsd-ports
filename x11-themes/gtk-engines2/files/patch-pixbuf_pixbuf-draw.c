--- pixbuf/pixbuf-draw.c.orig	Mon Aug 23 11:59:28 2004
+++ pixbuf/pixbuf-draw.c	Mon Aug 23 12:00:13 2004
@@ -75,7 +75,7 @@
 	continue;
 
       if (image->match_data.detail &&
-	  (!image->match_data.detail ||
+	  (!match_data->detail ||
 	   strcmp (match_data->detail, image->match_data.detail) != 0))
       continue;
 
