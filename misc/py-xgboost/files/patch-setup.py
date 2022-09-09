--- setup.py.orig	2022-08-22 08:36:38 UTC
+++ setup.py
@@ -60,7 +60,7 @@ def copy_tree(src_dir: str, target_dir: str) -> None:
 
     src = os.path.join(src_dir, 'src')
     inc = os.path.join(src_dir, 'include')
-    dmlc_core = os.path.join(src_dir, 'dmlc-core')
+    #dmlc_core = os.path.join(src_dir, 'dmlc-core')
     gputreeshap = os.path.join(src_dir, "gputreeshap")
     rabit = os.path.join(src_dir, 'rabit')
     cmake = os.path.join(src_dir, 'cmake')
@@ -68,7 +68,7 @@ def copy_tree(src_dir: str, target_dir: str) -> None:
 
     clean_copy_tree(src, os.path.join(target_dir, 'src'))
     clean_copy_tree(inc, os.path.join(target_dir, 'include'))
-    clean_copy_tree(dmlc_core, os.path.join(target_dir, 'dmlc-core'))
+    #clean_copy_tree(dmlc_core, os.path.join(target_dir, 'dmlc-core'))
     clean_copy_tree(gputreeshap, os.path.join(target_dir, "gputreeshap"))
     clean_copy_tree(rabit, os.path.join(target_dir, 'rabit'))
     clean_copy_tree(cmake, os.path.join(target_dir, 'cmake'))
@@ -142,7 +142,7 @@ class BuildExt(build_ext.build_ext):  # pylint: disabl
 
     def build_cmake_extension(self) -> None:
         '''Configure and build using CMake'''
-        if USER_OPTIONS['use-system-libxgboost'][2]:
+        if True or USER_OPTIONS['use-system-libxgboost'][2]: # see https://github.com/dmlc/xgboost/issues/6879
             self.logger.info('Using system libxgboost.')
             return
 
@@ -239,7 +239,7 @@ class InstallLib(install_lib.install_lib):
     def install(self) -> List[str]:
         outfiles = super().install()
 
-        if USER_OPTIONS['use-system-libxgboost'][2] != 0:
+        if True or USER_OPTIONS['use-system-libxgboost'][2] != 0: # see https://github.com/dmlc/xgboost/issues/6879
             self.logger.info('Using system libxgboost.')
             lib_path = os.path.join(sys.prefix, 'lib')
             msg = 'use-system-libxgboost is specified, but ' + lib_name() + \
