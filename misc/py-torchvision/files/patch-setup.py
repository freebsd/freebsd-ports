-- Add FreeBSD support for finding PNG/JPEG/WebP libraries in setup.py.
-- On Linux, setup.py auto-detects these libraries in /usr/include and /usr/local/include.
-- On FreeBSD, the same paths are used so extend the platform checks to include FreeBSD.
-- Also add FreeBSD to find_libpng() which uses libpng-config (available on FreeBSD).
-- This replaces the TORCHVISION_INCLUDE workaround that caused duplicate torch header
-- inclusion errors due to conflicting system and Python package torch headers.
-- Also fall back to wheel.bdist_wheel when setuptools.command.bdist_wheel is not available:
-- devel/py-setuptools in the ports tree is older than setuptools 70.1 which introduced it.

--- setup.py.orig	2026-10-28 11:19:32 UTC
+++ setup.py
@@ -10,7 +10,10 @@ from pathlib import Path
 from importlib.metadata import distribution, PackageNotFoundError
 from pathlib import Path
 
-import setuptools.command.bdist_wheel
+try:
+    from setuptools.command.bdist_wheel import bdist_wheel as _bdist_wheel
+except ImportError:
+    from wheel.bdist_wheel import bdist_wheel as _bdist_wheel
 
 import torch
 from packaging.version import parse as parse_version
@@ -235,7 +238,7 @@ def find_libpng():
 
 def find_libpng():
     # Returns (found, include dir, library dir, library name)
-    if sys.platform in ("linux", "darwin", "aix"):
+    if sys.platform in ("linux", "darwin", "aix") or sys.platform.startswith("freebsd"):
         libpng_config = shutil.which("libpng-config")
         if libpng_config is None:
             warnings.warn("libpng-config not found")
@@ -298,7 +301,7 @@ def find_library(header):
                 return True, str(include_dir), str(library_dir)
         print(f"{searching_for}. Didn't find in {prefix_env_var}.")
 
-    if sys.platform == "linux":
+    if sys.platform in ("linux",) or sys.platform.startswith("freebsd"):
         for prefix in (Path("/usr/include"), Path("/usr/local/include")):
             if (prefix / header).exists():
                 print(f"{searching_for}. Found in {prefix}.")
@@ -394,7 +397,7 @@ def make_image_stable_extension():
     )
 
 
-class bdist_wheel(setuptools.command.bdist_wheel.bdist_wheel):
+class bdist_wheel(_bdist_wheel):
     """Tag the wheel py3-none so that a single wheel covers every CPython, including
     the free-threaded ones."""
 
