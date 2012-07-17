--- ./docs/conf.py.orig	2012-07-16 23:28:27.000000000 +0200
+++ ./docs/conf.py	2012-07-16 23:28:52.000000000 +0200
@@ -247,4 +247,4 @@
 
 
 # Example configuration for intersphinx: refer to the Python standard library.
-intersphinx_mapping = {'http://docs.python.org/': None}
+intersphinx_mapping = {'http://docs.python.org/': '%%DISTDIR%%/%%PORTNAME%%/objects.inv'}
