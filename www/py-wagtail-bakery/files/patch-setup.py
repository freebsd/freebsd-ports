--- setup.py.orig	2023-03-18 17:46:16 UTC
+++ setup.py
@@ -4,7 +4,7 @@ with open('README.md', 'r') as fh:
     long_description = fh.read()
 
 install_requires = [
-    'django-bakery~=0.13.1',
+    'django-bakery>=0.12.7,<0.14',
     'wagtail>=4.1',
 ]
 
