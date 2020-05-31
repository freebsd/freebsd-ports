--- setup.py.orig	2019-10-27 01:15:11 UTC
+++ setup.py
@@ -25,11 +25,8 @@ setup(name='spf-engine',
     include_package_data=True,
     data_files=[(os.path.join('share', 'man', 'man1'),
         ['policyd-spf.1']), (os.path.join('share', 'man', 'man5'),
-        ['policyd-spf.conf.5']), (os.path.join('etc', 'python-policyd-spf'),
-        ['policyd-spf.conf']), (os.path.join('share', 'man', 'man5'),
-        ['policyd-spf.peruser.5']), (os.path.join('lib', 'systemd', 'system'),
-        ['system/pyspf-milter.service']),(os.path.join('etc', 'init.d'),
-        ['system/pyspf-milter']) ],
+        ['policyd-spf.conf.5']), (os.path.join('share', 'man', 'man5'),
+        ['policyd-spf.peruser.5'])],
     classifiers = [
         'Development Status :: 5 - Production/Stable',
         'Environment :: No Input/Output (Daemon)',
