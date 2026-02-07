--- src/cronoutils.c.orig	2013-12-04 14:46:09 UTC
+++ src/cronoutils.c
@@ -199,7 +199,7 @@ create_link(char *pfilename, 
     {
 	unlink(prevlinkname);
     }
-    if (stat(linkname, &stat_buf) == 0)
+    if (lstat(linkname, &stat_buf) == 0)
     {
 	if (prevlinkname) {
 	    rename(linkname, prevlinkname);
