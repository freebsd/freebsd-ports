--- cronolog-1.6.2/src/cronoutils.c.orig	Thu May  3 17:43:21 2001
+++ cronolog-1.6.2/src/cronoutils.c	Mon Dec 11 00:48:23 2006
@@ -199,7 +199,7 @@
     {
 	unlink(prevlinkname);
     }
-    if (stat(linkname, &stat_buf) == 0)
+    if (lstat(linkname, &stat_buf) == 0)
     {
 	if (prevlinkname) {
 	    rename(linkname, prevlinkname);
