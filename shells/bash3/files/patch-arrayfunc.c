#
# Fix segfault when accessing an unset array
#
# http://lists.gnu.org/archive/html/bug-bash/2004-08/msg00026.html
#
--- arrayfunc.c.orig	Fri Dec 19 00:03:09 2003
+++ arrayfunc.c	Sun Aug  1 20:43:00 2004
@@ -611,7 +611,7 @@
   var = find_variable (t);
 
   free (t);
-  return var;
+  return (var == 0 || invisible_p (var)) ? (SHELL_VAR *)0 : var;
 }
 
 /* Return a string containing the elements in the array and subscript
