--- src/parser_dirops.adb.orig	Wed Aug 31 17:10:45 2005
+++ src/parser_dirops.adb	Thu Sep  1 20:42:27 2005
@@ -127,6 +127,7 @@
   ParseExpression( expr_val, expr_type );
   if baseTypesOk( expr_type, dirops_dir_name_str_t ) then
      if token = symbol_t and identifiers( token ).value = "," then
+        err( "second parameter not supported by the compiler that built this version of BUSH"); -- GNAT 3.15
         expect( symbol_t, "," );
         ParseExpression( expr_val2, expr_type2 );
         if baseTypesOk( expr_type2, boolean_t ) then
@@ -139,7 +140,8 @@
     recursive : boolean := expr_val2 = to_unbounded_string( "1" );
   begin
     if isExecutingCommand then
-       Remove_Dir( dir_name_str( to_string( expr_val ) ), recursive);
+       -- Remove_Dir( dir_name_str( to_string( expr_val ) ), recursive);
+       Remove_Dir( dir_name_str( to_string( expr_val ) ) );
     end if;
   exception when directory_error =>
     err( "directory cannot be removed" );
@@ -300,6 +302,7 @@
   ParseExpression( expr_val, expr_type );
   if baseTypesOk( expr_type, dirops_path_name_t ) then
      if token = symbol_t and identifiers( token ).value = "," then
+        err( "second parameter not supported by the compiler that built this version of BUSH"); -- GNAT 3.15
         expect( symbol_t, "," );
         ParseExpression( expr_val2, expr_type2 );
         if baseTypesOk( expr_type2, dirops_env_style_t ) then
@@ -308,22 +311,23 @@
      end if;
   end if;
   expect( symbol_t, ")" );
-  declare
-    style : environment_style := System_Default;
+  -- declare
+  --   style : environment_style := System_Default;
   begin
-    if isExecutingCommand then
-       -- not very elegant
-       if expr_val2 = to_unbounded_string( "0" ) then
-          style := UNIX;
-       elsif expr_val2 = to_unbounded_string( "1" ) then
-          style := DOS;
-       elsif expr_val2 = to_unbounded_string( "2" ) then
-          style := Both;
-       elsif expr_val2 = to_unbounded_string( "3" ) then
-          style := System_Default;
-       end if;
-       result := to_unbounded_string( expand_path( path_name( to_string( expr_val ) ), style ) );
-    end if;
+  --   if isExecutingCommand then
+  --      -- not very elegant
+  --      if expr_val2 = to_unbounded_string( "0" ) then
+  --         style := UNIX;
+  --      elsif expr_val2 = to_unbounded_string( "1" ) then
+  --         style := DOS;
+  --      elsif expr_val2 = to_unbounded_string( "2" ) then
+  --         style := Both;
+  --      elsif expr_val2 = to_unbounded_string( "3" ) then
+  --         style := System_Default;
+  --      end if;
+  --     result := to_unbounded_string( expand_path( path_name( to_string( expr_val ) ), style ) );
+       result := to_unbounded_string( expand_path( path_name( to_string( expr_val ) ) ) );
+    --end if;
   exception when directory_error =>
     err( "directory not accessible" );
   when others =>
