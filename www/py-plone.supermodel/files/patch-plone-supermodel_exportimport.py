--- ./plone/supermodel/exportimport.py.orig	2012-04-15 17:56:36.000000000 +0400
+++ ./plone/supermodel/exportimport.py	2012-04-25 00:12:57.000000000 +0400
@@ -1,4 +1,4 @@
-from elementtree import ElementTree
+from xml.etree import ElementTree
 
 from zope.interface import Interface, implements, implementedBy
 from zope.component import queryUtility
