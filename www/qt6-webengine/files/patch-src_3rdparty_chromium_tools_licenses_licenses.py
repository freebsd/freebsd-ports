--- src/3rdparty/chromium/tools/licenses/licenses.py.orig	2023-08-16 19:50:41 UTC
+++ src/3rdparty/chromium/tools/licenses/licenses.py
@@ -618,6 +618,8 @@ def _GnBinary():
   exe = 'gn'
   if sys.platform.startswith('linux'):
     subdir = 'linux64'
+  elif sys.platform.startswith('freebsd'):
+    subdir = '../../../../.build/install/bin'
   elif sys.platform == 'darwin':
     subdir = 'mac'
   elif sys.platform == 'win32':
