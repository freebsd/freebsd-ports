--- src/3rdparty/chromium/tools/licenses.py.orig	2023-07-22 20:07:18 UTC
+++ src/3rdparty/chromium/tools/licenses.py
@@ -582,6 +582,8 @@ def _GnBinary():
   exe = 'gn'
   if sys.platform.startswith('linux'):
     subdir = 'linux64'
+  elif sys.platform.startswith('freebsd'):
+    subdir = '../../../../.build/install/bin'
   elif sys.platform == 'darwin':
     subdir = 'mac'
   elif sys.platform == 'win32':
