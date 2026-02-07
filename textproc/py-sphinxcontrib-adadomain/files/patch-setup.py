Obtained from:	https://bitbucket.org/tkoskine/sphinxcontrib-adadomain/commits/0adaafc635791511af623027bd2cf57375763a27

--- setup.py.orig	2018-01-19 18:39:44 UTC
+++ setup.py
@@ -12,7 +12,7 @@ This package contains the adadomain Sphinx extension.
 
 '''
 
-requires = ['Sphinx>=1.0']
+requires = ['Sphinx>=1.4']
 
 with open(path.join(here, 'README.rst'), encoding='utf-8') as f:
     long_description = f.read()
