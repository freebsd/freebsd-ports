--- setup.py.orig	2011-12-25 21:31:34.267830738 +0000
+++ setup.py	2011-12-25 21:32:29.325688840 +0000
@@ -25,7 +25,7 @@
 if 'SYSCONFDIR' in os.environ:
     etc_path = os.environ['SYSCONFDIR']
 else:
-    etc_path = os.path.join(os.path.dirname(PREFIX), 'etc')
+    etc_path = os.path.join('%%PREFIX%%', 'etc')
 
 setup(
       name=NAME,
@@ -69,10 +69,10 @@
                'scripts/salt-run',
                'scripts/salt'],
       data_files=[(os.path.join(etc_path, 'salt'),
-                    ['conf/master',
-                     'conf/minion',
+                    ['conf/master.sample',
+                     'conf/minion.sample',
                     ]),
-                ('share/man/man1',
+                ('man/man1',
                     ['doc/man/salt-master.1',
                      'doc/man/salt-key.1',
                      'doc/man/salt.1',
@@ -82,14 +82,11 @@
                      'doc/man/salt-run.1',
                      'doc/man/salt-minion.1',
                     ]),
-                ('share/man/man7',
+                ('man/man7',
                     ['doc/man/salt.7',
                     ]),
                 (mod_path,
                     ['salt/modules/cytest.pyx',
                     ]),
-                (doc_path,
-                    ['LICENSE'
-                    ]),
                  ],
      )
