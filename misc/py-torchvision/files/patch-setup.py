-- Add FreeBSD support for finding PNG/JPEG/WebP libraries in setup.py.
-- On Linux, setup.py auto-detects these libraries in /usr/include and /usr/local/include.
-- On FreeBSD, the same paths are used so extend the platform checks to include FreeBSD.
-- Also add FreeBSD to find_libpng() which uses libpng-config (available on FreeBSD).
-- This replaces the TORCHVISION_INCLUDE workaround that caused duplicate torch header
-- inclusion errors due to conflicting system and Python package torch headers.

--- setup.py.orig	2025-01-01 00:00:00 UTC
+++ setup.py
@@ -198,7 +198,7 @@
 
 def find_libpng():
     # Returns (found, include dir, library dir, library name)
-    if sys.platform in ("linux", "darwin", "aix"):
+    if sys.platform in ("linux", "darwin", "aix") or sys.platform.startswith("freebsd"):
         libpng_config = shutil.which("libpng-config")
         if libpng_config is None:
             warnings.warn("libpng-config not found")
@@ -261,7 +261,7 @@
                 return True, str(include_dir), str(library_dir)
         print(f"{searching_for}. Didn't find in {prefix_env_var}.")
 
-    if sys.platform == "linux":
+    if sys.platform in ("linux",) or sys.platform.startswith("freebsd"):
         for prefix in (Path("/usr/include"), Path("/usr/local/include")):
             if (prefix / header).exists():
                 print(f"{searching_for}. Found in {prefix}.")
