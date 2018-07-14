--- cli/libtecla/expand.c.orig	2018-07-11 16:57:16 UTC
+++ cli/libtecla/expand.c
@@ -322,7 +322,7 @@ FileExpansion *ef_expand_file(ExpandFile
  * If the caller specified that the whole of path[] be matched,
  * work out the corresponding length.
  */
-  if(pathlen < 0 || pathlen > strlen(path))
+  if(pathlen < 0 || (unsigned long)(pathlen) > strlen(path))
     pathlen = strlen(path);
 /*
  * Discard previous expansion results.
