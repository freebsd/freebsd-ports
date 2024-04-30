--- src/3rdparty/chromium/tools/licenses/licenses.py.orig	2023-12-12 22:08:45 UTC
+++ src/3rdparty/chromium/tools/licenses/licenses.py
@@ -751,6 +751,8 @@ def _GnBinary():
   exe = 'gn'
   if sys.platform.startswith('linux'):
     subdir = 'linux64'
+  elif sys.platform.startswith('freebsd'):
+    subdir = '../../../../.build/install/bin'
   elif sys.platform == 'darwin':
     subdir = 'mac'
   elif sys.platform == 'win32':
