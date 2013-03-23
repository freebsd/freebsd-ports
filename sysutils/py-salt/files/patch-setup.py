--- ./setup.py.orig	2013-03-19 08:58:34.000000000 +0400
+++ ./setup.py	2013-03-20 20:15:36.000000000 +0400
@@ -156,7 +156,7 @@
 if 'SYSCONFDIR' in os.environ:
     etc_path = os.environ['SYSCONFDIR']
 else:
-    etc_path = os.path.join(os.path.dirname(PREFIX), 'etc')
+    etc_path = os.path.join('%%PREFIX%%', 'etc')
 
 with open(salt_reqs) as f:
     lines = f.read().split('\n')
@@ -209,7 +209,7 @@
                              'salt.utils',
                              ],
                 'package_data': {'salt.modules': ['rh_ip/*.jinja']},
-                'data_files': [('share/man/man1',
+                'data_files': [('man/man1',
                                 ['doc/man/salt-master.1',
                                  'doc/man/salt-key.1',
                                  'doc/man/salt.1',
@@ -219,7 +219,7 @@
                                  'doc/man/salt-run.1',
                                  'doc/man/salt-minion.1',
                                  ]),
-                               ('share/man/man7', ['doc/man/salt.7']),
+                               ('man/man7', ['doc/man/salt.7']),
                                ],
                 # Required for esky builds
                 'install_requires': requirements,
