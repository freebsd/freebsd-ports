--- third_party/dawn/tools/python/cipd_deps.py.orig	2026-08-13 16:48:13 UTC
+++ third_party/dawn/tools/python/cipd_deps.py
@@ -49,7 +49,7 @@ def get_cipd_compatible_current_os() -> str:
     The returned string is compatible with CIPD's package naming scheme.
     """
     current_platform = sys.platform
-    if current_platform in ('linux', 'cygwin'):
+    if syscurrent_platform.startswith(('linux', 'cygwin', 'openbsd', 'freebsd')):
         return 'linux'
     if current_platform == 'win32':
         return 'windows'
