-- Add builtins.open wrapper to support /dev/fd/N paths on FreeBSD when fdescfs is not mounted.
-- This ensures that unit tests can run successfully in environments where /dev/fd is unavailable.

--- test/test.py.orig	2026-09-25 00:00:00 UTC
+++ test/test.py
@@ -11,6 +11,21 @@ import sys

 sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))
 from yq import cli, yq  # noqa

+import builtins
+original_open = builtins.open
+def patched_open(file, *args, **kwargs):
+    if isinstance(file, str) and file.startswith('/dev/fd/'):
+        try:
+            fd = int(file.split('/')[-1])
+            dup_fd = os.dup(fd)
+            mode = args[0] if args else kwargs.get('mode', 'r')
+            return os.fdopen(dup_fd, mode, *args[1:], **{k: v for k, v in kwargs.items() if k != 'mode'})
+        except Exception:
+            pass
+    return original_open(file, *args, **kwargs)
+builtins.open = patched_open
+
+
 USING_PYPY = True if platform.python_implementation() == "PyPy" else False
