--- torch/distributed/elastic/multiprocessing/redirects.py.orig	2026-05-13 17:40:44 UTC
+++ torch/distributed/elastic/multiprocessing/redirects.py
@@ -47,7 +47,9 @@ def get_libc():
             "msvcr110, msvcr100). Redirects cannot function without a CRT."
         )
     else:
-        return ctypes.CDLL("libc.so.6")
+        import ctypes.util
+        libc_name = ctypes.util.find_library("c") or "libc.so.6"
+        return ctypes.CDLL(libc_name)
 
 
 libc = get_libc()
