--- turpial/main.py.orig	2011-03-23 17:50:07.000000000 +0100
+++ turpial/main.py	2011-03-27 11:35:32.000000000 +0200
@@ -21,8 +21,8 @@
 
 try:
     import ctypes
-    libc = ctypes.CDLL('libc.so.6')
-    libc.prctl(15, 'turpial', 0, 0)
+    libc = ctypes.CDLL(os.path.join('/usr/lib', 'libc.so'))
+    libc.setproctitle('turpial')
 except ImportError:
     pass
 
