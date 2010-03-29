--- thunar-vfs/thunar-vfs-thumb.c.orig	2009-01-12 21:38:49.000000000 +0100
+++ thunar-vfs/thunar-vfs-thumb.c	2010-03-29 08:32:55.000000000 +0200
@@ -1169,7 +1169,7 @@
     goto done0;
 
   /* verify the png signature */
-  if (G_LIKELY (png_check_sig ((png_bytep) signature, sizeof (signature))))
+  if (G_LIKELY (!png_sig_cmp ((png_bytep) signature, 0, sizeof (signature))))
     rewind (fp);
   else
     goto done0;
