--- mod_dav.h.orig	Tue Nov 11 14:16:48 2003
+++ mod_dav.h	Tue Nov 11 14:17:18 2003
@@ -1431,6 +1431,7 @@
 
     dav_text *propstat_404;	/* (cached) propstat giving a 404 error */
 
+    int is_dir;                 /* state for dav_fs_walker(): should we recurse? */
     /* for COPY and MOVE operations */
     int is_move;
     dav_buffer work_buf;
