--- v8/tools/metagen/metagen.py.orig	2026-10-18 13:29:39 UTC
+++ v8/tools/metagen/metagen.py
@@ -315,12 +315,6 @@ def main() -> int:
     builtin_headers_dir = os.path.abspath(args.clang_builtin_headers_dir)
     flag = "--clang-builtin-headers-dir"
     probe = os.path.join(builtin_headers_dir, "stddef.h")
-  if not os.path.isfile(probe):
-    print(
-        f"[metagen] {flag} does not hold clang's builtin headers:\n"
-        f"  {probe} not found",
-        file=sys.stderr)
-    return 1
   # -fsyntax-only, -ferror-limit=, -resource-dir= and -D carry `CLOption`
   # visibility in clang's Options.td, so one spelling works under both
   # drivers. -isystem does NOT: the clang-cl driver drops it with an
