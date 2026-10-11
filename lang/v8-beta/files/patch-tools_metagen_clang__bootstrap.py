--- tools/metagen/clang_bootstrap.py.orig	2026-10-08 04:42:29 UTC
+++ tools/metagen/clang_bootstrap.py
@@ -158,6 +158,11 @@ def bootstrap_native(native_so: str,
     sys.exit(1)
   cindex.Config.set_library_file(native_so)
 
+  # cindex before LLVM 21 defines Cursor.__eq__ without __hash__, which
+  # makes cursors unhashable; metagen keeps them in sets.
+  if cindex.Cursor.__hash__ is None:
+    cindex.Cursor.__hash__ = lambda self: self.hash
+
   # Log the libclang version and warn if it is older than the clang
   # toolchain, so a mismatch is discoverable.
   get_version = getattr(cindex.Config(), "get_clang_version", None)
