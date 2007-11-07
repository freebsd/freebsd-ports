--- gcc-3.3.1/gcc/cp/decl.c.ORIG	2007-10-17 11:39:05.000000000 -0400
+++ gcc-3.3.1/gcc/cp/decl.c	2007-10-17 11:26:47.000000000 -0400
@@ -677,6 +677,13 @@
    ? cp_function_chain->bindings		\
    : scope_chain->bindings)
 
+#define set_current_binding_level(x)            \
+{                                               \
+  if(cfun && cp_function_chain->bindings)       \
+     cp_function_chain->bindings = (x);         \
+     else scope_chain->bindings = (x);          \
+}
+
 /* The binding level of the current class, if any.  */
 
 #define class_binding_level scope_chain->class_bindings
@@ -724,7 +731,7 @@
      are active.  */
   memset ((char*) newlevel, 0, sizeof (struct cp_binding_level));
   newlevel->level_chain = current_binding_level;
-  current_binding_level = newlevel;
+  set_current_binding_level(newlevel);
   newlevel->tag_transparent = tag_transparent;
   newlevel->more_cleanups_ok = 1;
 
@@ -780,7 +787,7 @@
     }
   {
     register struct cp_binding_level *level = current_binding_level;
-    current_binding_level = current_binding_level->level_chain;
+    set_current_binding_level(current_binding_level->level_chain);
     level->level_chain = free_binding_level;
     if (level->parm_flag != 2)
       binding_table_free (level->type_decls);
@@ -797,7 +804,7 @@
 suspend_binding_level ()
 {
   if (class_binding_level)
-    current_binding_level = class_binding_level;
+    set_current_binding_level(class_binding_level);
 
   if (NAMESPACE_LEVEL (global_namespace))
     my_friendly_assert (!global_scope_p (current_binding_level), 20030527);
@@ -816,7 +823,7 @@
         }
       is_class_level = 0;
     }
-  current_binding_level = current_binding_level->level_chain;
+  set_current_binding_level(current_binding_level->level_chain);
   find_class_binding_level ();
 }
 
@@ -829,7 +836,7 @@
   my_friendly_assert(!class_binding_level, 386);
   /* Also, resuming a non-directly nested namespace is a no-no.  */
   my_friendly_assert(b->level_chain == current_binding_level, 386);
-  current_binding_level = b;
+  set_current_binding_level(b);
   if (ENABLE_SCOPE_CHECKING)
     {
       b->binding_depth = binding_depth;
@@ -4529,9 +4536,9 @@
   else
     {
       b = current_binding_level;
-      current_binding_level = level;
+      set_current_binding_level(level);
       x = pushdecl (x);
-      current_binding_level = b;
+      set_current_binding_level(b);
     }
   current_function_decl = function_decl;
   POP_TIMEVAR_AND_RETURN (TV_NAME_LOOKUP, x);
@@ -6933,7 +6940,7 @@
   current_lang_name = lang_name_c;
 
   current_function_decl = NULL_TREE;
-  current_binding_level = NULL_BINDING_LEVEL;
+  set_current_binding_level(NULL_BINDING_LEVEL);
   free_binding_level = NULL_BINDING_LEVEL;
 
   build_common_tree_nodes (flag_signed_char);
@@ -10766,10 +10773,10 @@
   if (decl_context == NORMAL && !toplevel_bindings_p ())
     {
       struct cp_binding_level *b = current_binding_level;
-      current_binding_level = b->level_chain;
+      set_current_binding_level(b->level_chain);
       if (current_binding_level != 0 && toplevel_bindings_p ())
 	decl_context = PARM;
-      current_binding_level = b;
+      set_current_binding_level(b);
     }
 
   if (name == NULL)
@@ -14406,7 +14413,7 @@
      FIXME factor out the non-RTL stuff.  */
   bl = current_binding_level;
   init_function_start (decl1, input_filename, lineno);
-  current_binding_level = bl;
+  set_current_binding_level(bl);
 
   /* Even though we're inside a function body, we still don't want to
      call expand_expr to calculate the size of a variable-sized array.
