--- plone/supermodel/serializer.py.orig	2011-04-29 22:24:50.000000000 +0400
+++ plone/supermodel/serializer.py	2011-09-22 23:06:40.000000000 +0400
@@ -15,7 +15,7 @@
 
 from plone.supermodel.utils import sortedFields, prettyXML
 
-from elementtree import ElementTree
+from xml.etree import ElementTree
 
 
 class DefaultFieldNameExtractor(object):
