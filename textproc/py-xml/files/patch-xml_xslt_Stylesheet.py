--- xml/xslt/Stylesheet.py.orig	2015-02-16 16:52:28 UTC
+++ xml/xslt/Stylesheet.py
@@ -373,8 +373,8 @@ class StylesheetElement(XsltElement):
 
         #Attribute sets
         attribute_sets = filter(lambda x: x.nodeType == Node.ELEMENT_NODE and (x.namespaceURI, x.localName) == (XSL_NAMESPACE, 'attribute-set'), self.childNodes)
-        for as in attribute_sets:
-            as.instantiate(context, processor)
+        for las in attribute_sets:
+            las.instantiate(context, processor)
         overridden_params = {}
         for k in topLevelParams.keys():
             if type(k) != types.TupleType:
