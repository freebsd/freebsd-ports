--- setup.py    2012-03-21 11:46:26.000000000 -0600
+++ setup.py    2012-03-24 14:01:33.965200298 -0600
@@ -47,7 +47,7 @@
 if 'SYSCONFDIR' in os.environ:
     etc_path = os.environ['SYSCONFDIR']
 else:
-    etc_path = os.path.join(os.path.dirname(PREFIX), 'etc')
+    etc_path = os.path.join('%%PREFIX%%', 'etc')

 libraries = ['ws2_32'] if sys.platform == 'win32' else []

@@ -98,10 +98,10 @@
                'scripts/salt-run',
                'scripts/salt'],
       data_files=[(os.path.join(etc_path, 'salt'),
-                    ['conf/master.template',
-                     'conf/minion.template',
+                    ['conf/master.sample',
+                     'conf/minion.sample',
                     ]),
-                ('share/man/man1',
+                ('man/man1',
                     ['doc/man/salt-master.1',
                      'doc/man/salt-key.1',
                      'doc/man/salt.1',
@@ -111,9 +111,8 @@
                      'doc/man/salt-run.1',
                      'doc/man/salt-minion.1',
                     ]),
-                ('share/man/man7',
+                ('man/man7',
                     ['doc/man/salt.7',
                     ]),
                  ],
-      install_requires=requirements,
      )
