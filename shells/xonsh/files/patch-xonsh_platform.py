--- xonsh/platform.py.orig	2026-02-04 16:49:54 UTC
+++ xonsh/platform.py
@@ -576,7 +576,7 @@ def LIBC():
             libc = None
     elif ON_BSD:
         try:
-            libc = ctypes.CDLL("libc.so")
+            libc = ctypes.CDLL(ctypes.util.find_library("c"))
         except AttributeError:
             libc = None
         except OSError:
