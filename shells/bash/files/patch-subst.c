#
# Fix broken array expansion
#
# http://lists.gnu.org/archive/html/bug-bash/2004-08/msg00192.html
#
--- subst.c.orig	Sun Jul  4 13:56:13 2004
+++ subst.c	Thu Aug 12 13:36:17 2004
@@ -4891,7 +4891,7 @@
   if (*e1p < 0)		/* negative offsets count from end */
     *e1p += len;
 
-  if (*e1p >= len || *e1p < 0)
+  if (*e1p > len || *e1p < 0)
     return (-1);
 
 #if defined (ARRAY_VARS)
