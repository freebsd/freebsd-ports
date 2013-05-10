--- setup.py	2013-04-12 09:52:56.331750634 -0600
+++ setup.py.new	2013-04-12 09:53:45.274752559 -0600
@@ -145,8 +145,8 @@
       package_data={
           'saltcloud': ['deploy/*.sh'],
       },
-      data_files=[('share/man/man1', ['doc/man/salt-cloud.1']),
-                  ('share/man/man7', ['doc/man/salt-cloud.7'])
+      data_files=[('man/man1', ['doc/man/salt-cloud.1']),
+                  ('man/man7', ['doc/man/salt-cloud.7'])
                   ],
       scripts=['scripts/salt-cloud'],
       cmdclass={
