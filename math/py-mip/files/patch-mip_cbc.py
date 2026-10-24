--- mip/cbc.py.orig	2026-08-18 01:34:07 UTC
+++ mip/cbc.py
@@ -72,11 +72,15 @@ try:
     else:
         import cbcbox as _cbcbox
 
-        _lib_dir = _cbcbox.cbc_lib_dir()
+        _lib_dir = "%%PREFIX%%/lib"
         if "linux" in platform.lower():
             if not os_is_64_bit:
                 raise NotImplementedError("Linux 32 bits platform not supported.")
             libfile = os.path.join(_lib_dir, "libCbc.so")
+        elif "freebsd" in platform.lower():
+            if not os_is_64_bit:
+                raise NotImplementedError("Linux 32 bits platform not supported.")
+            libfile = os.path.join(_lib_dir, "libCbcSolver.so")
         elif platform.lower().startswith("win"):
             if not os_is_64_bit:
                 raise NotImplementedError("Win32 platform not supported.")
