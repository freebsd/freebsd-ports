#
# Fix brace expansion following quoted text
#
# http://lists.gnu.org/archive/html/bug-bash/2004-09/msg00255.html
#
--- braces.c.orig	Wed Sep  8 11:07:53 2004
+++ braces.c	Fri Sep 17 18:42:36 2004
@@ -402,7 +402,8 @@
 	{
 	  pass_next = 1;
 	  i++;
-	  level++;
+	  if (quoted == 0)
+	    level++;
 	  continue;
 	}
 #endif
