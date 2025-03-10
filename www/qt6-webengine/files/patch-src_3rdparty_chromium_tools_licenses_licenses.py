--- src/3rdparty/chromium/tools/licenses/licenses.py.orig	2024-07-03 01:14:49 UTC
+++ src/3rdparty/chromium/tools/licenses/licenses.py
@@ -816,6 +816,8 @@ def _GnBinary():
   exe = 'gn'
   if sys.platform.startswith('linux'):
     subdir = 'linux64'
+  elif sys.platform.startswith('freebsd'):
+    subdir = '../../../../.build/install/bin'
   elif sys.platform == 'darwin':
     subdir = 'mac'
   elif sys.platform == 'win32':
