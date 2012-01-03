--- plone/app/registry/exportimport/handler.py.orig	2011-09-19 17:44:47.000000000 +0400
+++ plone/app/registry/exportimport/handler.py	2011-09-19 19:40:05.000000000 +0400
@@ -1,6 +1,6 @@
 from zope.component import queryUtility
 
-from elementtree import ElementTree
+from xml.etree import ElementTree
 
 from zope.dottedname.resolve import resolve
 
