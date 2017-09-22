--- xonsh/platform.py.orig	2017-03-12 02:36:40 UTC
+++ xonsh/platform.py
@@ -491,7 +491,7 @@ def LIBC():
         libc = ctypes.CDLL('cygwin1.dll')
     elif ON_BSD:
         try:
-            libc = ctypes.CDLL('libc.so')
+      	     libc = ctypes.CDLL(ctypes.util.find_library("c"))
         except AttributeError:
             libc = None
         except OSError:
