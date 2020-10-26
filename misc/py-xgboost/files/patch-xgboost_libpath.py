--- xgboost/libpath.py.orig	2020-10-12 22:10:16 UTC
+++ xgboost/libpath.py
@@ -4,6 +4,7 @@
 import os
 import platform
 import sys
+import sysconfig # from https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=247408#c0
 
 
 class XGBoostLibraryNotFound(Exception):
@@ -20,6 +21,8 @@ def find_lib_path():
     """
     curr_path = os.path.dirname(os.path.abspath(os.path.expanduser(__file__)))
     dll_path = [
+	sysconfig.get_config_var('LIBDIR'), # from https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=247408#c0
+	os.path.join(sys.prefix, 'xgboost'),
         # normal, after installation `lib` is copied into Python package tree.
         os.path.join(curr_path, 'lib'),
         # editable installation, no copying is performed.
