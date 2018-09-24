--- salt/loader.py
+++ salt/loader.py
@@ -1240,7 +1240,7 @@
                 try:
                     pycache_files = [
                         os.path.join('__pycache__', x) for x in
-                        sorted(os.listdir(os.path.join(mod_dir, '__pycache__')))
+                        sorted(os.listdir(os.path.join(mod_dir, '__pycache__'))) if not x.endswith('opt-1.pyc') and not x.endswith('opt-2.pyc')
                     ]
                 except OSError:
                     pass
