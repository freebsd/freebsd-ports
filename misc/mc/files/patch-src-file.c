--- src/file.c.orig	Fri Dec 27 01:04:10 2002
+++ src/file.c	Tue Jun 15 03:15:09 2004
@@ -366,7 +366,7 @@
 	dst_is_symlink = 0;
 
   retry_src_readlink:
-    len = mc_readlink (src_path, link_target, MC_MAXPATHLEN);
+    len = mc_readlink (src_path, link_target, MC_MAXPATHLEN - 1);
     if (len < 0) {
 	return_status =
 	    file_error (_(" Cannot read source link \"%s\" \n %s "),
@@ -715,6 +715,7 @@
 	    gettimeofday (&tv_current, NULL);
 
 	    if (n_read > 0) {
+		char *t = buf;
 		n_read_total += n_read;
 
 		/* Windows NT ftp servers report that files have no
@@ -729,9 +730,10 @@
 
 		/* dst_write */
 		while ((n_written =
-			mc_write (dest_desc, buf, n_read)) < n_read) {
+			mc_write (dest_desc, t, n_read)) < n_read) {
 		    if (n_written > 0) {
 			n_read -= n_written;
+			t += n_written;
 			continue;
 		    }
 		    return_status =
