--- libvo/vo_md5.c.orig	Mon Nov 11 10:20:26 2002
+++ libvo/vo_md5.c	Sun Jan 11 02:30:52 2004
@@ -56,7 +56,7 @@

     video_out_pgm.flip_page();

-    snprintf (buf2, 100, "md5sum %s", vo_pgm_filename);
+    snprintf (buf2, 100, "md5 %s", vo_pgm_filename);
     f = popen (buf2, "r");
     i = fread (buf2, 1, sizeof(buf2), f);
     pclose (f);
