--- work/salt-cloud-0.6.0/setup.py	2012-07-13 11:50:56.000000000 -0600
+++ setup.py	2012-07-16 13:07:15.901865171 -0600
@@ -45,9 +45,9 @@
       package_data={
           'saltcloud': ['deploy/*'],
           },
-      data_files=[('share/man/man1',
+      data_files=[('man/man1',
                      ['doc/man/salt-cloud.1']),
-                     ('share/man/man7',
+                     ('man/man7',
                      ['doc/man/salt-cloud.7'])],
       scripts=['scripts/salt-cloud'],
      )
