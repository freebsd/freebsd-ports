--- setup.py.orig	2010-03-28 18:26:24.000000000 +0800
+++ setup.py	2010-03-29 15:07:17.000000000 +0800
@@ -9,8 +9,8 @@
 import os
 sys.path += [os.getcwd()]
 
-import ez_setup
-ez_setup.use_setuptools(download_delay=2)
+#import ez_setup
+#ez_setup.use_setuptools(download_delay=2)
 from setuptools import setup, find_packages
 import re
 import imp
@@ -54,7 +54,7 @@
        author_email     = info['__email__'],
        entry_points     = {'console_scripts' : 'paragrep=paragrep:main'},
        install_requires = ['grizzled>=0.8.1', ],
-       data_files       = [('man', ['man/paragrep.1'])],
+#       data_files       = [('man', ['man/paragrep.1'])],
        classifiers = [
         'Intended Audience :: Developers',
         'Intended Audience :: System Administrators',
