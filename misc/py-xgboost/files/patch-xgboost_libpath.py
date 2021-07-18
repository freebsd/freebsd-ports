--- xgboost/libpath.py.orig	2021-04-20 00:31:38 UTC
+++ xgboost/libpath.py
@@ -5,6 +5,7 @@ import os
 import platform
 from typing import List
 import sys
+import sysconfig # from https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=247408#c0
 
 
 class XGBoostLibraryNotFound(Exception):
@@ -21,6 +22,8 @@ def find_lib_path() -> List[str]:
     """
     curr_path = os.path.dirname(os.path.abspath(os.path.expanduser(__file__)))
     dll_path = [
+	sysconfig.get_config_var('LIBDIR'), # from https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=247408#c0
+	os.path.join(sys.prefix, 'xgboost'),
         # normal, after installation `lib` is copied into Python package tree.
         os.path.join(curr_path, 'lib'),
         # editable installation, no copying is performed.
