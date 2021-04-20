--- setup.py.orig	2021-04-20 00:31:38 UTC
+++ setup.py
@@ -60,14 +60,14 @@ def copy_tree(src_dir, target_dir):
 
     src = os.path.join(src_dir, 'src')
     inc = os.path.join(src_dir, 'include')
-    dmlc_core = os.path.join(src_dir, 'dmlc-core')
+    #dmlc_core = os.path.join(src_dir, 'dmlc-core')
     rabit = os.path.join(src_dir, 'rabit')
     cmake = os.path.join(src_dir, 'cmake')
     plugin = os.path.join(src_dir, 'plugin')
 
     clean_copy_tree(src, os.path.join(target_dir, 'src'))
     clean_copy_tree(inc, os.path.join(target_dir, 'include'))
-    clean_copy_tree(dmlc_core, os.path.join(target_dir, 'dmlc-core'))
+    #clean_copy_tree(dmlc_core, os.path.join(target_dir, 'dmlc-core'))
     clean_copy_tree(rabit, os.path.join(target_dir, 'rabit'))
     clean_copy_tree(cmake, os.path.join(target_dir, 'cmake'))
     clean_copy_tree(plugin, os.path.join(target_dir, 'plugin'))
@@ -125,7 +125,7 @@ class BuildExt(build_ext.build_ext):  # pylint: disabl
 
     def build_cmake_extension(self):
         '''Configure and build using CMake'''
-        if USER_OPTIONS['use-system-libxgboost'][2]:
+        if True or USER_OPTIONS['use-system-libxgboost'][2]: # see https://github.com/dmlc/xgboost/issues/6879
             self.logger.info('Using system libxgboost.')
             return
 
@@ -217,7 +217,7 @@ class InstallLib(install_lib.install_lib):
     def install(self):
         outfiles = super().install()
 
-        if USER_OPTIONS['use-system-libxgboost'][2] != 0:
+        if True or USER_OPTIONS['use-system-libxgboost'][2] != 0: # see https://github.com/dmlc/xgboost/issues/6879
             self.logger.info('Using system libxgboost.')
             lib_path = os.path.join(sys.prefix, 'lib')
             msg = 'use-system-libxgboost is specified, but ' + lib_name() + \
