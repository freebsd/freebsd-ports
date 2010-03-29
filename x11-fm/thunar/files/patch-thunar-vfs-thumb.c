--- work.bk/Thunar-1.0.1/thunar-vfs/thunar-vfs-thumb.c	2009-01-12 12:38:49.000000000 -0800
+++ work/Thunar-1.0.1/thunar-vfs/thunar-vfs-thumb.c	2010-03-28 19:57:36.000000000 -0700
@@ -1169,7 +1169,7 @@
     goto done0;
 
   /* verify the png signature */
-  if (G_LIKELY (png_check_sig ((png_bytep) signature, sizeof (signature))))
+  if (G_LIKELY (!png_sig_cmp ((png_bytep) signature, 0, sizeof (signature))))
     rewind (fp);
   else
     goto done0;
