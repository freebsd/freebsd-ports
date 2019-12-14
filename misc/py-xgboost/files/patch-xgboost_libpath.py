--- xgboost/libpath.py.orig	2019-12-14 21:46:06 UTC
+++ xgboost/libpath.py
@@ -20,7 +20,7 @@ def find_lib_path():
     """
     curr_path = os.path.dirname(os.path.abspath(os.path.expanduser(__file__)))
     # make pythonpack hack: copy this directory one level upper for setup.py
-    dll_path = [curr_path, os.path.join(curr_path, '../../lib/'),
+    dll_path = [os.getenv('FREEBSD_LIBRARY_PATH'),
                 os.path.join(curr_path, './lib/'),
                 os.path.join(sys.prefix, 'xgboost')]
     if sys.platform == 'win32':
