--- pwman/exchange/importer.py.orig	2007-02-04 21:44:43.000000000 +0300
+++ pwman/exchange/importer.py	2011-08-29 21:07:49.000000000 +0400
@@ -17,7 +17,7 @@
 # Copyright (C) 2006 Ivan Kelly <ivan@ivankelly.net>
 #============================================================================
 
-import cElementTree as ET
+import xml.etree.cElementTree as ET
 from pwman.data.nodes import Node
 from pwman.data.tags import Tag
 
