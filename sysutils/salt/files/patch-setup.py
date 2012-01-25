--- salt-0.9.6/setup.py 2012-01-21 02:18:08.000000000 +0000
+++ setup.py    2012-01-22 19:21:35.158004570 +0000
@@ -44,7 +44,7 @@
 if 'SYSCONFDIR' in os.environ:
     etc_path = os.environ['SYSCONFDIR']
 else:
-    etc_path = os.path.join(os.path.dirname(PREFIX), 'etc')
+    etc_path = os.path.join('%%PREFIX%%', 'etc')
 
 libraries = ['ws2_32'] if sys.platform == 'win32' else []
 
@@ -91,10 +91,10 @@
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
@@ -104,7 +104,7 @@
                      'doc/man/salt-run.1',
                      'doc/man/salt-minion.1',
                     ]),
-                ('share/man/man7',
+                ('man/man7',
                     ['doc/man/salt.7',
                     ]),
                  ],
