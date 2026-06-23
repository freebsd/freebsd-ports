-- Exclude the "benchmark" package from installation. It is a benchmarking
-- utility included in the source distribution but not intended to be installed
-- as a top-level package, where it would conflict with other packages.
--- setup.py.orig	2026-06-23 16:35:00 UTC
+++ setup.py
@@ -37,7 +37,7 @@ setup(
     keywords="pack rectangle packing rectangles enclosing 2D",
     url="https://github.com/Penlect/rectangle-packer",
     ext_modules=ext_modules,
-    packages=find_packages(exclude=("test",)),
+    packages=find_packages(exclude=("test", "benchmark")),
     include_package_data=True,
     python_requires=">=3.9",
     classifiers=[
