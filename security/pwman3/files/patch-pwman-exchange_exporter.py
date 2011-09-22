--- pwman/exchange/exporter.py.orig	2007-02-04 21:44:43.000000000 +0300
+++ pwman/exchange/exporter.py	2011-08-29 21:07:59.000000000 +0400
@@ -17,7 +17,7 @@
 # Copyright (C) 2006 Ivan Kelly <ivan@ivankelly.net>
 #============================================================================
 
-from cElementTree import Element, SubElement, dump, ElementTree
+from xml.etree.cElementTree import Element, SubElement, dump, ElementTree
 from pwman.data.nodes import Node
 from pwman.data.tags import Tag
 
