--- ./setup.py.orig	2012-10-24 04:51:35.000000000 +0400
+++ ./setup.py	2012-10-24 16:30:49.000000000 +0400
@@ -93,7 +93,7 @@
 if 'SYSCONFDIR' in os.environ:
     etc_path = os.environ['SYSCONFDIR']
 else:
-    etc_path = os.path.join(os.path.dirname(PREFIX), 'etc')
+    etc_path = os.path.join('%%PREFIX%%', 'etc')
 
 libraries = ['ws2_32'] if sys.platform == 'win32' else []
 
@@ -139,7 +139,7 @@
                              'salt.utils',
                              ],
                 'package_data': {'salt.modules': ['rh_ip/*.jinja']},
-                'data_files': [('share/man/man1',
+                'data_files': [('man/man1',
                                 ['doc/man/salt-master.1',
                                  'doc/man/salt-key.1',
                                  'doc/man/salt.1',
@@ -149,7 +149,7 @@
                                  'doc/man/salt-run.1',
                                  'doc/man/salt-minion.1',
                                  ]),
-                               ('share/man/man7', ['doc/man/salt.7']),
+                               ('man/man7', ['doc/man/salt.7']),
                                ],
                 'install_requires': requirements,
                 # The dynamic module loading in salt.modules makes this
