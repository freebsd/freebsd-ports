--- setup.py.orig	2013-12-01 00:26:15.000000000 +0100
+++ setup.py	2013-12-01 00:28:32.000000000 +0100
@@ -3,13 +3,10 @@
 
 from mptt import VERSION
 
-requires=('Django>=1.4.2',)
 try:
     from setuptools import setup
-    kwargs ={'install_requires': requires}
 except ImportError:
     from distutils.core import setup
-    kwargs = {'requires': requires}
 
 # Dynamically calculate the version based on mptt.VERSION
 version_tuple = VERSION
@@ -40,5 +37,4 @@
         str('Programming Language :: Python :: 3'),
         str('Topic :: Utilities'),
     ],
-    **kwargs
 )
