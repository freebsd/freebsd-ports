Description: Fix the python_requires specifier: '>=3.6.*' is not a valid
  version specifier (a .* suffix is only allowed with == and !=), and
  current packaging rejects it.
Issue ID: none (upstream inactive)
Changeset: none
TODO: Drop once a release fixes the specifier.

--- setup.py.orig	2022-07-23 19:42:05 UTC
+++ setup.py
@@ -53,7 +53,7 @@ setup(
     packages=find_packages(exclude=['tests']),
     package_dir={'': '.'},
     test_suite='tests',
-    python_requires='>=3.6.*',
+    python_requires='>=3.6',
     include_package_data=True,
     data_files=DATA_FILES,
     install_requires=[
