--- ./setup.py.orig	2013-10-17 21:27:29.000000000 +0400
+++ ./setup.py	2013-10-25 10:43:51.000000000 +0400
@@ -313,7 +313,7 @@
                              'salt.log.handlers',
                              ],
                 'package_data': {'salt.modules': ['rh_ip/*.jinja']},
-                'data_files': [('share/man/man1',
+                'data_files': [('man/man1',
                                 ['doc/man/salt-master.1',
                                  'doc/man/salt-key.1',
                                  'doc/man/salt.1',
@@ -324,7 +324,7 @@
                                  'doc/man/salt-ssh.1',
                                  'doc/man/salt-minion.1',
                                  ]),
-                               ('share/man/man7', ['doc/man/salt.7']),
+                               ('man/man7', ['doc/man/salt.7']),
                                ],
                 # Required for esky builds
                 'install_requires': REQUIREMENTS,
