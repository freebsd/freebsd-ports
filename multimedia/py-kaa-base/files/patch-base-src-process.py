--- src/process.py.orig	2009-05-25 16:47:25.000000000 -0400
+++ src/process.py	2009-05-29 13:38:51.000000000 -0400
@@ -75,7 +75,7 @@
             try:
                 # Python 2.5
                 import ctypes
-                ctypes.CDLL("libc.so.6").siginterrupt(signal.SIGCHLD, 0)
+                ctypes.CDLL("libc.so").siginterrupt(signal.SIGCHLD, 0)
             except (ImportError, OSError):
                 # Python 2.4- is not supported.
                 raise SystemError('kaa.base requires Python 2.5 or later')
