--- tempfile.c.orig	Mon Jul  4 14:43:35 2005
+++ tempfile.c	Mon Jul  4 14:43:48 2005
@@ -26,7 +26,7 @@
   taia_tai(&now,&sec);
 
   /* Record the second timestamp on the string. */
-  secbuf[fmt_uint64(secbuf,(uint64) sec.x - 4611686018427387904)] = '\0';
+  secbuf[fmt_uint64(secbuf,(uint64) sec.x - 4611686018427387904ULL)] = '\0';
   if (!stralloc_cats(tmpf, secbuf)) die_nomem();
   
   /* Append the microsecond timestamp to the string. */
