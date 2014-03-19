--- ./setup.py.orig	2014-03-06 10:50:27.000000000 +0200
+++ ./setup.py	2014-03-06 10:52:20.000000000 +0200
@@ -451,12 +451,12 @@
                                     'virt/*.jinja'
                                     ],
                                 },
-                'data_files': [('share/man/man1',
+                'data_files': [('man/man1',
                                 ['doc/man/salt-cp.1',
                                  'doc/man/salt-call.1',
                                  'doc/man/salt-minion.1',
                                  ]),
-                               ('share/man/man7',
+                               ('man/man7',
                                 ['doc/man/salt.7',
                                  ]),
                                ],
