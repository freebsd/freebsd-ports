--- execute_cmd.c.shellfunc	Tue Jan 25 11:29:11 2000
+++ execute_cmd.c	Tue May  2 21:26:24 2000
@@ -2762,6 +2762,8 @@
   if (tc && (flags & CMD_IGNORE_RETURN))
     tc->flags |= CMD_IGNORE_RETURN;
 
+  old_shell_function = this_shell_function;
+
   if (subshell == 0)
     {
       begin_unwind_frame ("function_calling");
@@ -2843,6 +2845,8 @@
 
   if (variable_context == 0 || this_shell_function == 0)
     make_funcname_visible (0);
+
+  this_shell_function = old_shell_function;
 
   return (result);
 }
