--- setup.py.orig	2020-05-25 18:12:50 UTC
+++ setup.py
@@ -57,14 +57,14 @@ def copy_tree(src_dir, target_dir):
 
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
