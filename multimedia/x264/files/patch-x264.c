--- x264.c.orig	Sun Oct  2 21:04:20 2005
+++ x264.c	Sun Oct  2 21:04:34 2005
@@ -1475,7 +1475,7 @@
         return -1;
 
     memset(p_mp4, 0, sizeof(mp4_t));
-    p_mp4->p_file = gf_isom_open(psz_filename, GF_ISOM_OPEN_WRITE, NULL);
+    p_mp4->p_file = gf_isom_open(psz_filename, GF_ISOM_OPEN_WRITE);
 
     if ((p_mp4->p_sample = gf_isom_sample_new()) == NULL)
     {
