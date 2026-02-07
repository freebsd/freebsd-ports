--- setup.py.orig	2023-02-27 01:07:17 UTC
+++ setup.py
@@ -118,11 +118,7 @@ setup(
     include_package_data=True,
     data_files=[(os.path.join('share', 'man', 'man5'),
         ['man/dkimpy-milter.conf.5']), (os.path.join('share', 'man', 'man8'),
-        ['man/dkimpy-milter.8']), (os.path.join('etc', 'dkimpy-milter'),
-        ['etc/dkimpy-milter.conf']), (os.path.join('lib', 'systemd', 'system'),
-        ['system/dkimpy-milter.service']),(os.path.join('etc', 'init.d'),
-        ['system/dkimpy-milter']), (os.path.join('etc', 'init.d'),
-        ['system/dkimpy-milter.openrc'])],
+        ['man/dkimpy-milter.8'])],
     zip_safe = False,
     cmdclass={
         'expand': FileMacroExpand,
