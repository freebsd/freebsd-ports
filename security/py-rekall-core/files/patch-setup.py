--- setup.py.orig	2016-11-03 22:17:38 UTC
+++ setup.py
@@ -51,27 +51,27 @@ def find_data_files(source):
 # approach ensures that any Rekall version will always work as tested - even
 # when external packages are upgraded in an incompatible way.
 install_requires = [
-    "artifacts == 20160114",
-    "pyaff4 >= 0.24, < 0.30",
-    "PyYAML == 3.11",
-    "acora == 2.0",
-    "arrow == 0.7.0",
-    "efilter == 1!1.3",
-    "intervaltree == 2.1.0",
-    "pycrypto == 2.6.1",
-    "pyelftools == 0.24",
-    "pyparsing==2.1.5",
-    "pytz == 2016.4",
-    "psutil >= 4.0, < 5.0",
-    "rekall-capstone == 3.0.4.post2",
-    "rekall-yara == 3.4.0.1",
-    "sortedcontainers == 1.4.4",
-    "pytsk3 == 20160721",
-    "ipaddr==2.1.11",
+    "artifacts >= 20160114",
+    "pyaff4 >= 0.24",
+    "PyYAML >= 3.11",
+    "acora >= 2.0",
+    "arrow >= 0.7.0",
+    "efilter >= 1!1.3",
+    "intervaltree >= 2.1.0",
+    "pycrypto >= 2.6.1",
+    "pyelftools >= 0.24",
+    "pyparsing>=2.1.5",
+    "pytz >= 2016.4",
+    "psutil >= 4.0",
+    "capstone >= 3.0.4",
+    "yara-python >= 3.4.0",
+    "sortedcontainers >= 1.4.4",
+    "pytsk3 >= 20160721",
+    "ipaddr>=2.1.11",
 
     # Version 2.5.0 is broken with pyinstaller.
     # https://github.com/pyinstaller/pyinstaller/issues/1848
-    "python-dateutil == 2.5.3",
+    "python-dateutil >= 2.5.3",
 ]
 
 if "VIRTUAL_ENV" not in os.environ:
