--- xgboost/libpath.py.orig	2023-12-19 07:49:41 UTC
+++ xgboost/libpath.py
@@ -5,6 +5,7 @@ import os
 import platform
 import sys
 from typing import List
+import sysconfig # from https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=247408#c0
 
 
 class XGBoostLibraryNotFound(Exception):
@@ -21,6 +22,8 @@ def find_lib_path() -> List[str]:
     """
     curr_path = os.path.dirname(os.path.abspath(os.path.expanduser(__file__)))
     dll_path = [
+	sysconfig.get_config_var('LIBDIR'), # from https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=247408#c0
+	os.path.join(sys.prefix, 'xgboost'),
         # normal, after installation `lib` is copied into Python package tree.
         os.path.join(curr_path, "lib"),
         # editable installation, no copying is performed.
