#
# Fix broken array expansion
#
# http://lists.gnu.org/archive/html/bug-bash/2004-09/msg00097.html
#
--- subst.c.orig	Thu Aug 12 13:36:17 2004
+++ subst.c	Thu Sep  9 11:54:22 2004
@@ -4900,7 +4900,7 @@
     case VT_ARRAYVAR:
       a = (ARRAY *)value;
       /* For arrays, the first value deals with array indices. */
-      len = array_max_index (a);	/* arrays index from 0 to n - 1 */
+      len = array_max_index (a) + 1;	/* arrays index from 0 to n - 1 */
       break;
 #endif
     }
