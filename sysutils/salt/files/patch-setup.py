--- setup.py	2012-04-28 08:33:41.000000000 +0400
+++ setup.py	2012-05-02 01:08:12.000000000 +0400
@@ -47,7 +47,7 @@
 if 'SYSCONFDIR' in os.environ:
     etc_path = os.environ['SYSCONFDIR']
 else:
-    etc_path = os.path.join(os.path.dirname(PREFIX), 'etc')
+    etc_path = os.path.join('%%PREFIX%%', 'etc')

 libraries = ['ws2_32'] if sys.platform == 'win32' else []
 
@@ -100,7 +100,7 @@
                'scripts/salt-call',
                'scripts/salt-run',
                'scripts/salt'],
-      data_files=[('share/man/man1',
+      data_files=[('man/man1',
                     ['doc/man/salt-master.1',
                      'doc/man/salt-key.1',
                      'doc/man/salt.1',
@@ -110,7 +110,7 @@
                      'doc/man/salt-run.1',
                      'doc/man/salt-minion.1',
                     ]),
-                ('share/man/man7',
+                ('man/man7',
                     ['doc/man/salt.7',
                     ]),
                  ],
