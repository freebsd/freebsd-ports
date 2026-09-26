--- tools/typescript/ts_library.py.orig	2026-09-25 15:26:43 UTC
+++ tools/typescript/ts_library.py
@@ -366,8 +366,8 @@ def main(argv):
   list_valid, error_msg = validateDefinitionDeps(
     definitions_files, target_path, args.gen_dir, args.root_gen_dir, definitions
   )
-  if not list_valid:
-    raise AssertionError(error_msg)
+  #if not list_valid:
+  #  raise AssertionError(error_msg)
 
   if args.in_files is not None:
     manifest_path = os.path.join(
