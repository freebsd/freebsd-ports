-- Add builtins.open wrapper to support /dev/fd/N paths on FreeBSD when fdescfs is not mounted.
-- This ensures that unit tests can run successfully in environments where /dev/fd is unavailable.

--- test/test.py.orig	2026-11-04 11:23:34.858154000 -0800
+++ test/test.py	2026-11-04 11:23:40.624432000 -0800
@@ -15,6 +15,20 @@
 
 USING_PYPY = platform.python_implementation() == "PyPy"
 
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
 yaml_with_tags = """
 foo: !vault |
   $ANSIBLE_VAULT;1.1;AES256
