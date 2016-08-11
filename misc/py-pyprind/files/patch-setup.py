--- setup.py.orig	2016-04-14 15:46:12 UTC
+++ setup.py
@@ -39,6 +39,7 @@ setup(name='PyPrind',
           'Programming Language :: Python :: 2.7',
           'Programming Language :: Python :: 3',
           'Environment :: Console'],
+      test_suite = "nose.collector",
       long_description="""
 
 The PyPrind (Python Progress Indicator) module provides a progress
