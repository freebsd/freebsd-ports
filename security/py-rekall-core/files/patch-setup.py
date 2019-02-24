--- setup.py.orig	2019-01-04 00:51:27 UTC
+++ setup.py
@@ -53,27 +53,27 @@ def find_data_files(source):
 # when external packages are upgraded in an incompatible way.
 install_requires = [
     'PyYAML',
-    'acora==2.1',
-    'arrow==0.10.0',
-    'artifacts==20170909',
+    'acora>=2.1',
+    'arrow>=0.10.0',
+    'artifacts>=20170909',
     'future',
-    'intervaltree==2.1.0',
-    'ipaddr==2.2.0',
-    'parsedatetime==2.4',
+    'intervaltree>=2.1.0',
+    'ipaddr>=2.2.0',
+    'parsedatetime>=2.4',
     "psutil >= 5.0, < 6.0",
     'pyaff4 >= 0.26, < 0.30',
-    'pycryptodome==3.4.7',
-    'pyelftools==0.24',
-    'pyparsing==2.1.5',
-    'python-dateutil==2.6.1',
-    'pytsk3==20170802',
-    'pytz==2017.3',
-    'rekall-capstone==3.0.5.post2',
+    'pycryptodome>=3.4.7',
+    'pyelftools>=0.24',
+    'pyparsing>=2.1.5',
+    'python-dateutil>=2.6.1',
+    'pytsk3>=20170802',
+    'pytz>=2017.3',
+    'capstone>=3.0.5',
     "rekall-efilter >= 1.6, < 1.7",
 
     # Should match exactly the version of this package.
     'rekall-lib',
-    'rekall-yara==3.6.3.1',
+    'yara-python>=3.6.3.1',
 ]
 
 
