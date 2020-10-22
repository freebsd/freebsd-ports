--- salt/loader.py.orig	2020-10-22 05:33:25 UTC
+++ salt/loader.py
@@ -1468,7 +1468,7 @@ class LazyLoader(salt.utils.lazy.LazyDict):
             try:
                 pycache_files = [
                     os.path.join("__pycache__", x)
-                    for x in sorted(os.listdir(os.path.join(mod_dir, "__pycache__")))
+                    for x in sorted(os.listdir(os.path.join(mod_dir, '__pycache__'))) if not x.endswith('opt-1.pyc') and not x.endswith('opt-2.pyc')
                 ]
             except OSError:
                 pass
