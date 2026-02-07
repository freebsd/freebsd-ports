--- setup.py.orig	2018-01-08 17:58:49 UTC
+++ setup.py
@@ -1,7 +1,6 @@
 #!/usr/bin/env python
 
 import os
-import pypandoc
 
 # Notes for the not-an-everyday-python-dev for package distribution on pypi
 #
@@ -45,10 +44,6 @@ except ImportError:
     from setuptools import setup
 
 long_description = 'This library provides the python client for the Packet API.'
-if os.path.isfile('README.md') and os.path.isfile('CHANGELOG.md'):
-    readme = pypandoc.convert_file('README.md', 'rst')
-    changelog = pypandoc.convert_file('CHANGELOG.md', 'rst')
-    long_description = readme + '\n' + changelog
 
 setup(
     name='packet-python',
@@ -61,7 +56,6 @@ setup(
     keywords='packet api client',
     packages=['packet'],
     install_requires='requests',
-    setup_requires='pypandoc',
     classifiers=[
         'Development Status :: 5 - Production/Stable',
         'Intended Audience :: Developers',
