#
# Fix segmentation fault in unset typeset array variable
#
# http://lists.gnu.org/archive/html/bug-bash/2004-08/msg00190.html
#
--- variables.c.orig	Sun Jul  4 13:57:26 2004
+++ variables.c	Wed Aug  4 15:28:04 2004
@@ -1599,7 +1599,10 @@
   /* local foo; local foo;  is a no-op. */
   old_var = find_variable (name);
   if (old_var && local_p (old_var) && old_var->context == variable_context)
-    return (old_var);
+    {
+      VUNSETATTR (old_var, att_invisible);
+      return (old_var);
+    }
 
   was_tmpvar = old_var && tempvar_p (old_var);
   if (was_tmpvar)
