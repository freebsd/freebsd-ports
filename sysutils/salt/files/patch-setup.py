--- work/salt-0.10.2/setup.py.orig	2012-07-16 20:33:03.000000000 -0600
+++ setup.py	2012-07-31 20:53:47.983862084 -0600
@@ -71,7 +71,7 @@
 if 'SYSCONFDIR' in os.environ:
     etc_path = os.environ['SYSCONFDIR']
 else:
-    etc_path = os.path.join(os.path.dirname(PREFIX), 'etc')
+    etc_path = os.path.join('%%PREFIX%%', 'etc')
 
 libraries = ['ws2_32'] if sys.platform == 'win32' else []
 
@@ -115,7 +115,7 @@
                              'salt.utils',
                              ],
                 'package_data': {'salt.modules': ['rh_ip/*.jinja']},
-                'data_files': [('share/man/man1',
+                'data_files': [('man/man1',
                                 ['doc/man/salt-master.1',
                                  'doc/man/salt-key.1',
                                  'doc/man/salt.1',
@@ -125,9 +125,8 @@
                                  'doc/man/salt-run.1',
                                  'doc/man/salt-minion.1',
                                  ]),
-                               ('share/man/man7', ['doc/man/salt.7']),
+                               ('man/man7', ['doc/man/salt.7']),
                                ],
-                'install_requires': requirements,
                 }
 
 if with_setuptools:
