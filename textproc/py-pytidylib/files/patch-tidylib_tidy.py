--- tidylib/tidy.py.orig	2016-11-16 01:49:58 UTC
+++ tidylib/tidy.py
@@ -29,8 +29,7 @@ from .sink import create_sink, destroy_s
 __all__ = ['Tidy', 'PersistentTidy']
 
 # Default search order for library names if nothing is passed in
-LIB_NAMES = ['libtidy', 'libtidy.so', 'libtidy-0.99.so.0', 'cygtidy-0-99-0',
-             'tidylib', 'libtidy.dylib', 'tidy']
+LIB_NAMES = ['libtidy-0.99.so.0']
 
 # Error code from library
 ENOMEM = -12
@@ -84,7 +83,7 @@ class Tidy(object):
     def __init__(self, lib_names=None):
         self._tidy = None
         if lib_names is None:
-            lib_names = ctypes.util.find_library('tidy') or LIB_NAMES
+            lib_names = LIB_NAMES
         if isinstance(lib_names, str):
             lib_names = [lib_names]
         for name in lib_names:
