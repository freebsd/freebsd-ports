--- v8/src/builtins/builtins-iterator-gen.cc.orig	2019-01-09 20:18:02.120534000 +0100
+++ v8/src/builtins/builtins-iterator-gen.cc	2019-01-09 21:49:23.285517000 +0100
@@ -284,12 +284,12 @@
 
   BIND(&check_string);
   {
+    Label string_fast_call(this);
     StringBuiltinsAssembler string_assembler(state());
-    GotoIfNot(string_assembler.IsStringPrimitiveWithNoCustomIteration(iterable,
-                                                                      context),
-              &slow_path);
+    string_assembler.BranchIfStringPrimitiveWithNoCustomIteration(
+        iterable, context, &string_fast_call, &slow_path);
 
-    // Fast path for strings.
+    BIND(&string_fast_call);
     TailCallBuiltin(Builtins::kStringToList, context, iterable);
   }
 
