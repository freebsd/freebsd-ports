--- setup.py.orig	2017-09-05 13:29:08 UTC
+++ setup.py
@@ -33,8 +33,8 @@ install_requires = [
     'cached-property >= 1.2.0, < 2',
     'docopt >= 0.6.1, < 0.7',
     'PyYAML >= 3.10, < 4',
-    'requests >= 2.6.1, != 2.11.0, < 2.12',
-    'texttable >= 0.9.0, < 0.10',
+    'requests >= 2.6.1, != 2.11.0, < 3',
+    'texttable >= 0.9.0, < 1',
     'websocket-client >= 0.32.0, < 1.0',
     'docker >= 2.5.1, < 3.0',
     'dockerpty >= 0.4.1, < 0.5',
