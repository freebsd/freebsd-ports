--- v8/tools/metagen/metagen.py.orig	2026-11-17 21:17:00 UTC
+++ v8/tools/metagen/metagen.py
@@ -300,12 +300,6 @@ def main() -> int:
   # LLVM revision and so always matches the parsing library.
   resource_dir = os.path.abspath(args.clang_resource_dir)
   stddef = os.path.join(resource_dir, "include", "stddef.h")
-  if not os.path.isfile(stddef):
-    print(
-        f"[metagen] --clang-resource-dir does not hold clang's builtin "
-        f"headers:\n  {stddef} not found",
-        file=sys.stderr)
-    return 1
 
   prefix = [
       "-fsyntax-only",
