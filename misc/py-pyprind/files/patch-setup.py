--- setup.py.orig	2021-04-18 17:12:43 UTC
+++ setup.py
@@ -16,7 +16,7 @@ VERSION = pyprind.__version__
 
 VERSION = pyprind.__version__
 
-setup(name='PyPrind',
+setup(name='pyprind',
       version=VERSION,
       description='Python Progress Bar and Percent Indicator Utility',
       author='Sebastian Raschka',
@@ -39,6 +39,7 @@ setup(name='PyPrind',
           'Programming Language :: Python :: 2.7',
           'Programming Language :: Python :: 3',
           'Environment :: Console'],
+      test_suite = "nose.collector",
       long_description="""
 
 The PyPrind (Python Progress Indicator) module provides a progress
