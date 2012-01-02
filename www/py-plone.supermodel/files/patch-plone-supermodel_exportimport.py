--- plone/supermodel/exportimport.py.orig	2011-05-13 20:28:08.000000000 +0400
+++ plone/supermodel/exportimport.py	2011-09-22 23:05:55.000000000 +0400
@@ -1,4 +1,4 @@
-from elementtree import ElementTree
+from xml.etree import ElementTree
 
 from zope.interface import Interface, implements, implementedBy
 from zope.component import queryUtility
