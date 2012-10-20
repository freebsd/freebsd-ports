--- src/munged/xgetgrent.c.orig	2012-10-18 16:42:46.000000000 +0200
+++ src/munged/xgetgrent.c	2012-10-18 16:43:17.000000000 +0200
@@ -194,7 +194,7 @@
 
 #if   HAVE_GETGRENT_R_GNU
     rv = getgrent_r (gr, buf, buflen, &gr_ptr);
-    if (rv == ENOENT) {
+    if (((rv == ENOENT) || (rv == 0)) && (gr_ptr == NULL)) {
         got_eof = 1;
     }
     else if (rv != 0) {
