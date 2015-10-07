--- src/util/marmalade.py.orig	2007-11-07 18:53:47 UTC
+++ src/util/marmalade.py
@@ -448,4 +448,5 @@ def unjellyFromXML(stringOrFile):
     return unjellyFromDOM(document)
 
 
-from twisted.web.microdom import Text, Element, Node, Document, parse, parseString, CDATASection, NodeList
+from twisted.web.microdom import Text, Element, Node, Document, parse, parseString, CDATASection
+from types import ListType as Nodelist
