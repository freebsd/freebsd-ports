--- pgp.c.orig	Thu Jan 27 21:30:04 2005
+++ pgp.c	Fri Feb  4 13:14:04 2005
@@ -209,7 +209,7 @@
     if (armor_header)
     {
       char *p = mutt_skip_whitespace (buf);
-      if (*p == '\n') 
+      if (*p == '\0') 
 	armor_header = 0;
       continue;
     }
