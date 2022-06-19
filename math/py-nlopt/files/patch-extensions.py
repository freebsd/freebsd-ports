--- extensions.py.orig	2022-06-19 20:42:31 UTC
+++ extensions.py
@@ -25,7 +25,7 @@ class NLOptBuild(build_ext):
         except OSError:
             raise RuntimeError("CMake must be installed")
 
-        if platform.system() not in ("Windows", "Linux", "Darwin"):
+        if platform.system() not in ("Windows", "Linux", "Darwin", "FreeBSD"):
             raise RuntimeError(f"Unsupported os: {platform.system()}")
 
         for ext in self.extensions:
