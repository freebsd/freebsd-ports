-- Read README.rst instead of README.md
-- The PyPI sdist ships README.rst only, so the build fails with README.md missing
-- Upstream: https://github.com/atomgptlab/jarvis (sdist packaging issue, no upstream issue filed)

--- setup.py.orig	2026-10-28 17:23:32 UTC
+++ setup.py
@@ -6,8 +6,7 @@ base_dir = os.path.dirname(__file__)
 JARVIS_DIR = os.path.dirname(os.path.abspath(__file__))
 
 base_dir = os.path.dirname(__file__)
-# with open(os.path.join(base_dir, "README.rst")) as f:
-with open(os.path.join(base_dir, "README.md")) as f:
+with open(os.path.join(base_dir, "README.rst")) as f:
     long_d = f.read()
 
 setup(
