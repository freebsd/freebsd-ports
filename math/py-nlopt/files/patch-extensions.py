--- extensions.py.orig	2024-04-03 02:23:20 UTC
+++ extensions.py
@@ -26,7 +26,7 @@ class NLOptBuild(build_ext):
         except OSError:
             raise RuntimeError("CMake must be installed")
 
-        if platform.system() not in ("Windows", "Linux", "Darwin"):
+        if platform.system() not in ("Windows", "Linux", "Darwin", "FreeBSD"):
             raise RuntimeError(f"Unsupported os: {platform.system()}")
 
         for ext in self.extensions:
