--- src/brave/script/lib/config.py.orig	2026-06-01 00:00:00 UTC
+++ src/brave/script/lib/config.py
@@ -5,13 +5,18 @@
 import os
 import sys
 
-PLATFORM = {
-    'cygwin': 'win32',
-    'darwin': 'darwin',
-    'linux2': 'linux',
-    'linux': 'linux',
-    'win32': 'win32',
-}[sys.platform]
+# sys.platform carries the major version on FreeBSD ('freebsd14', ...), so it
+# cannot be looked up in the table below.
+if sys.platform.startswith('freebsd'):
+    PLATFORM = 'freebsd'
+else:
+    PLATFORM = {
+        'cygwin': 'win32',
+        'darwin': 'darwin',
+        'linux2': 'linux',
+        'linux': 'linux',
+        'win32': 'win32',
+    }[sys.platform]
 
 SOURCE_ROOT = os.path.abspath(
     os.path.join(os.path.dirname(__file__), '..', '..'))
