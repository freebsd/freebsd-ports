--- xgboost/libpath.py.orig	2020-05-25 18:09:22 UTC
+++ xgboost/libpath.py
@@ -20,6 +20,8 @@ def find_lib_path():
     """
     curr_path = os.path.dirname(os.path.abspath(os.path.expanduser(__file__)))
     dll_path = [
+        os.getenv('FREEBSD_LIBRARY_PATH'),
+	os.path.join(sys.prefix, 'xgboost'),
         # normal, after installation `lib` is copied into Python package tree.
         os.path.join(curr_path, 'lib'),
         # editable installation, no copying is performed.
