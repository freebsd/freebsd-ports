-- Fix compatibility with setuptools < 77.0.3:
-- Older UnixCCompiler lacks compiler_so_cxx/linker_so_cxx/linker_exe_cxx
-- attributes; skip gracefully instead of raising AttributeError.
--- setup.py.orig	2026-09-30 21:13:27 UTC
+++ setup.py
@@ -359,7 +359,9 @@ def set_compiler_executables(cc: CCompiler) -> None:
                             ('linker_so_cxx', linker_so_args),
                             ('linker_exe_cxx', linker_exe_args)]:
         new_args = []
-        old_args = getattr(cc, name)
+        old_args = getattr(cc, name, None)
+        if old_args is None:
+            continue
 
         # Set executable
         if compiler is not None:
