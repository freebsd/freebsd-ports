#
# Fix nested brace vs. variable expansion
#
# http://lists.gnu.org/archive/html/bug-bash/2004-08/msg00056.html
#
--- braces.c.orig	Tue Aug 04 14:32:33 2004
+++ braces.c	Tue Aug 04 15:15:36 2004
@@ -402,6 +402,7 @@
 	{
 	  pass_next = 1;
 	  i++;
+	  level++;
 	  continue;
 	}
 #endif
