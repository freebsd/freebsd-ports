--- setup.py.orig	2010-04-03 20:46:52.000000000 +0800
+++ setup.py	2010-04-03 20:47:04.000000000 +0800
@@ -1,7 +1,6 @@
 #!/usr/bin/python
 # -*- coding: koi8-r -*-
 from distutils.core import setup,sys
-from setuptools import setup
 import os
 
 if sys.version < '2.2.3':
@@ -11,7 +10,7 @@ if sys.version < '2.2.3':
 
 # Set proper release version in source code also!!!
 setup(name='xmpppy',
-      version='0.5.0rc1',
+      version='0.5.0',
       author='Alexey Nezhdanov',
       author_email='snakeru@users.sourceforge.net',
       url='http://xmpppy.sourceforge.net/',
