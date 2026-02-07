--- src/scripts/install.py.orig	2025-02-06 16:19:41 UTC
+++ src/scripts/install.py
@@ -246,7 +246,7 @@ def main(args):
             makedirs(man1_dir)
 
             copy_file(os.path.join(cfg['build_dir'], 'botan.1'),
-                      os.path.join(man1_dir, 'botan.1'))
+                      os.path.join(man1_dir, 'botan%d.1' % (ver_major)))
 
     logging.info('Botan %s installation to %s complete', cfg['version'], cfg['prefix'])
     return 0
