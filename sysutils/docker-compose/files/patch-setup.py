--- setup.py.orig	2017-07-25 23:05:03 UTC
+++ setup.py
@@ -34,8 +34,8 @@ install_requires = [
     'colorama >= 0.3.7, < 0.4',
     'docopt >= 0.6.1, < 0.7',
     'PyYAML >= 3.10, < 4',
-    'requests >= 2.6.1, != 2.11.0, < 2.12',
-    'texttable >= 0.8.1, < 0.9',
+    'requests >= 2.6.1, != 2.11.0, < 3',
+    'texttable >= 0.8.1, < 1',
     'websocket-client >= 0.32.0, < 1.0',
     'docker >= 2.4.2, < 3.0',
     'dockerpty >= 0.4.1, < 0.5',
