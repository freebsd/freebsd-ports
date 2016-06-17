--- setup.py.orig	2016-05-23 16:08:02 UTC
+++ setup.py
@@ -46,23 +46,22 @@ def find_data_files(source):
 # approach ensures that any Rekall version will always work as tested - even
 # when external packages are upgraded in an incompatible way.
 install_requires = [
-    "PyAFF4 >= 0.23, < 0.30",
-    "PyYAML == 3.11",
-    "acora == 2.0",
-    "argparse == 1.4.0",
-    "arrow == 0.7.0",
-    "efilter == 1!1.2",
-    "intervaltree == 2.1.0",
-    "pycrypto == 2.6.1",
-    "pyelftools == 0.23",
-    "pytz == 2016.4",
-    "rekall-capstone == 3.0.4.post2",
-    "rekall-yara == 3.4.0.1",
-    "sortedcontainers == 1.4.4",
+    "PyAFF4 >= 0.23",
+    "PyYAML >= 3.11",
+    "acora >= 2.0",
+    "arrow >= 0.7.0",
+    "efilter >= 1!1.2",
+    "intervaltree >= 2.1.0",
+    "pycrypto >= 2.6.1",
+    "pyelftools >= 0.23",
+    "pytz >= 2016.4",
+    "capstone >= 3.0.4",
+    "yara-python >= 3.4.0",
+    "sortedcontainers >= 1.4.4",
 
     # Version 2.5.0 is broken with pyinstaller.
     # https://github.com/pyinstaller/pyinstaller/issues/1848
-    "python-dateutil == 2.5.3",
+    "python-dateutil >= 2.5.0",
 ]
 
 
