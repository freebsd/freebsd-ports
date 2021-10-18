--- salt/loader/lazy.py.orig	2021-09-27 17:31:38 UTC
+++ salt/loader/lazy.py
@@ -447,7 +447,7 @@ class LazyLoader(salt.utils.lazy.LazyDict):
             try:
                 pycache_files = [
                     os.path.join("__pycache__", x)
-                    for x in sorted(os.listdir(os.path.join(mod_dir, "__pycache__")))
+                    for x in sorted(os.listdir(os.path.join(mod_dir, '__pycache__'))) if not x.endswith('opt-1.pyc') and not x.endswith('opt-2.pyc')
                 ]
             except OSError:
                 pass
