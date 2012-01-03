--- plone/app/registry/tests/test_exportimport.py.orig	2011-09-19 17:44:47.000000000 +0400
+++ plone/app/registry/tests/test_exportimport.py	2011-09-19 19:39:48.000000000 +0400
@@ -2,7 +2,7 @@
 from plone.testing import zca
 
 from StringIO import StringIO
-from elementtree import ElementTree
+from xml.etree import ElementTree
 
 from zope.interface import alsoProvides
 from zope.component import provideUtility
