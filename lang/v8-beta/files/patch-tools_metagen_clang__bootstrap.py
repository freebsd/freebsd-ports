--- tools/metagen/clang_bootstrap.py.orig	2026-10-12 21:12:54 UTC
+++ tools/metagen/clang_bootstrap.py
@@ -158,6 +158,15 @@ def bootstrap_native(native_so: str,
     sys.exit(1)
   cindex.Config.set_library_file(native_so)
 
+  # cindex before LLVM 21 defines Cursor.__eq__ without __hash__, which
+  # makes cursors unhashable; metagen keeps them in sets.  Its __eq__ also
+  # passes non-Cursor operands such as None to libclang, which fails.
+  if cindex.Cursor.__hash__ is None:
+    _cursor_eq = cindex.Cursor.__eq__
+    cindex.Cursor.__eq__ = lambda self, other: (
+        isinstance(other, cindex.Cursor) and _cursor_eq(self, other))
+    cindex.Cursor.__hash__ = lambda self: self.hash
+
   # Log the libclang version and warn if it is older than the clang
   # toolchain, so a mismatch is discoverable.
   get_version = getattr(cindex.Config(), "get_clang_version", None)
