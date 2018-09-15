--- xonsh/platform.py.orig	2018-09-05 14:16:47 UTC
+++ xonsh/platform.py
@@ -571,7 +571,7 @@ def LIBC():
         libc = ctypes.CDLL("msys-2.0.dll")
     elif ON_BSD:
         try:
-            libc = ctypes.CDLL("libc.so")
+            libc = ctypes.CDLL(ctypes.util.find_library("c"))
         except AttributeError:
             libc = None
         except OSError:
