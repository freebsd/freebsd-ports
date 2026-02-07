--- setup.py.orig	2019-02-04 16:11:53 UTC
+++ setup.py
@@ -32,14 +32,14 @@ def find_version(*file_paths):
 install_requires = [
     'cached-property >= 1.2.0, < 2',
     'docopt >= 0.6.1, < 0.7',
-    'PyYAML >= 3.10, < 4.3',
-    'requests >= 2.6.1, != 2.11.0, != 2.12.2, != 2.18.0, < 2.21',
-    'texttable >= 0.9.0, < 0.10',
+    'PyYAML >= 3.10, < 6',
+    'requests >= 2.6.1, != 2.11.0, != 2.12.2, != 2.18.0, < 3',
+    'texttable >= 0.9.0, < 2',
     'websocket-client >= 0.32.0, < 1.0',
     'docker[ssh] >= 3.7.0, < 4.0',
     'dockerpty >= 0.4.1, < 0.5',
     'six >= 1.3.0, < 2',
-    'jsonschema >= 2.5.1, < 3',
+    'jsonschema >= 2.5.1, < 4',
 ]
 
 
