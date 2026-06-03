--- salt/loader/lazy.py.orig	2026-02-23 20:07:08 UTC
+++ salt/loader/lazy.py
@@ -540,7 +540,7 @@
             try:
                 pycache_files = [
                     os.path.join("__pycache__", x)
-                    for x in sorted(os.listdir(os.path.join(mod_dir, "__pycache__")))
+                    for x in sorted(os.listdir(os.path.join(mod_dir, "__pycache__"))) if not x.endswith('opt-1.pyc') and not x.endswith('opt-2.pyc')
                 ]
             except OSError:
                 pass
