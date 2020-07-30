--- setup.py.orig	2020-02-09 10:45:34 UTC
+++ setup.py
@@ -1,5 +1,7 @@
 #!/usr/bin/env python
 
+from io import open
+
 # Using setuptools rather than distutils to get the `develop` command
 from setuptools import setup
 
@@ -8,7 +10,7 @@ NAME = 'feedgenerator'
 PACKAGES = ['feedgenerator', 'feedgenerator.django',
             'feedgenerator.django.utils']
 DESCRIPTION = 'Standalone version of django.utils.feedgenerator'
-LONG_DESCRIPTION = open('README.rst').read()
+LONG_DESCRIPTION = open('README.rst', encoding='UTF-8').read()
 
 URL = "https://github.com/getpelican/feedgenerator"
 
