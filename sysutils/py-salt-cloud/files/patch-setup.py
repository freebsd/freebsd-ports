--- setup.py	2013-03-13 11:37:54.772115975 -0600
+++ setup.py	2013-03-13 11:38:21.415251065 -0600
@@ -67,8 +67,8 @@
       package_data={
           'saltcloud': ['deploy/*.sh'],
           },
-      data_files=[('share/man/man1', ['doc/man/salt-cloud.1']),
-                  ('share/man/man7', ['doc/man/salt-cloud.7'])
+      data_files=[('man/man1', ['doc/man/salt-cloud.1']),
+                  ('man/man7', ['doc/man/salt-cloud.7'])
                   ],
       scripts=['scripts/salt-cloud'],
       **setup_kwargs
