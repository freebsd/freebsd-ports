--- setup.py.orig	2026-10-11 13:51:40 UTC
+++ setup.py
@@ -9,7 +9,7 @@ import sys
 import os
 import sys
 
-LIB_ROOT = os.path.abspath(os.path.join(__file__, os.pardir, os.pardir))  
+LIB_ROOT = os.path.abspath(os.path.join(__file__, os.pardir, os.pardir))
 if os.getcwd() != LIB_ROOT:
     os.chdir(LIB_ROOT)
 if LIB_ROOT not in sys.path:
@@ -22,7 +22,7 @@ uclmodule = Extension(
 
 uclmodule = Extension(
     'ucl',
-    libraries=['ucl', 'curl'],
+    libraries=['ucl', 'fetch'],
     sources=['python/src/uclmodule.c'],
     include_dirs=['include'],
     language='c',
@@ -31,7 +31,7 @@ ucl_lib = {
 ucl_lib = {
     'sources': ['src/' + fn for fn in os.listdir('src') if fn.endswith('.c')],
     'include_dirs': ['include', 'src', 'uthash', 'klib'],
-    'macros': [('CURL_FOUND', '1')],
+    'macros': [('HAVE_FETCH_H', '1')],
 }
 
 # sdist setup() will pull in the *.c files automatically, but not headers
