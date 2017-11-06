--- setup_build.py.orig	2017-06-03 16:40:14 UTC
+++ setup_build.py
@@ -49,8 +49,8 @@ if sys.platform.startswith('win'):
         ('H5_BUILT_AS_DYNAMIC_LIB', None)
     ])
 else:
-    COMPILER_SETTINGS['include_dirs'].extend(['/opt/local/include''/usr/local/include'])
-    COMPILER_SETTINGS['library_dirs'].extend(['/opt/local/include''/usr/local/include'])
+    COMPILER_SETTINGS['include_dirs'].extend(['%%PREFIX%%/include'])
+    COMPILER_SETTINGS['library_dirs'].extend(['%%PREFIX%%/lib'])
 
 
 class h5py_build_ext(build_ext):
