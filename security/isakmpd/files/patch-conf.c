--- conf.c.orig	Mon Nov 18 06:58:04 2002
+++ conf.c	Sat Feb  8 11:39:43 2003
@@ -254,5 +254,5 @@
       if (!section)
 	{
-	  log_print ("conf_parse_line: %d: malloc (%d) failed", ln, i);
+	  log_print ("conf_parse_line: %d: malloc (%ld) failed", ln, (long) i);
 	  return;
 	}
