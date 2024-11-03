--- setup.py.orig	2024-10-18 20:21:39 UTC
+++ setup.py
@@ -26,11 +26,6 @@ if PY_MAJOR_VERSION < 3 and os.name == 'nt':
 if PY_MAJOR_VERSION < 3 and os.name == 'nt':
     raise Exception("Python 2 is not supported on Windows.")
 
-cyver = int(Cython.__version__.split(".")[0])
-if cyver < 3:
-    msg = "Cython version 3 or newer required"
-    raise Exception(msg)
-
 ext = '.pyx'
 
 
