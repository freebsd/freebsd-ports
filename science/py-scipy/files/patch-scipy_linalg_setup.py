--- scipy/linalg/setup.py.orig	2022-08-08 07:24:08 UTC
+++ scipy/linalg/setup.py
@@ -160,7 +160,7 @@ def configuration(parent_package='', top_path=None):
 
     # Add any license files
     config.add_data_files('src/id_dist/doc/doc.tex')
-    config.add_data_files('src/lapack_deprecations/LICENSE')
+    #config.add_data_files('src/lapack_deprecations/LICENSE')
 
     # Type stubs
     config.add_data_files('*.pyi')
