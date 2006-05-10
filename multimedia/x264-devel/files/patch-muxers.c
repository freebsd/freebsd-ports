--- muxers.c.orig	Tue May  9 22:04:27 2006
+++ muxers.c	Tue May  9 22:04:37 2006
@@ -647,7 +647,7 @@
         return -1;
 
     memset(p_mp4, 0, sizeof(mp4_t));
-    p_mp4->p_file = gf_isom_open(psz_filename, GF_ISOM_OPEN_WRITE, NULL);
+    p_mp4->p_file = gf_isom_open(psz_filename, GF_ISOM_OPEN_WRITE);
 
     if ((p_mp4->p_sample = gf_isom_sample_new()) == NULL)
     {
