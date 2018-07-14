--- cli/libtecla/homedir.c.orig	2018-07-11 18:41:32 UTC
+++ cli/libtecla/homedir.c
@@ -146,7 +146,7 @@ HomeDir *_new_HomeDir(void)
  * a pathname, increase its length.
  */
   pathlen = _pu_pathname_dim();
-  if(pathlen > home->buflen)
+  if(pathlen > (unsigned long)(home->buflen))
     home->buflen = pathlen;
 /*
  * Allocate a work buffer.
