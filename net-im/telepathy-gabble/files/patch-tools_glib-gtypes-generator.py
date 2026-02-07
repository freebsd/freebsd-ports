--- tools/glib-gtypes-generator.py.orig	2014-05-07 14:28:02 UTC
+++ tools/glib-gtypes-generator.py
@@ -68,13 +68,13 @@ class GTypesGenerator(object):
         self.need_other_arrays = {}
 
     def h(self, code):
-        self.header.append(code.encode("utf-8"))
+        self.header.append(code)
 
     def c(self, code):
-        self.body.append(code.encode("utf-8"))
+        self.body.append(code)
 
     def d(self, code):
-        self.docs.append(code.encode('utf-8'))
+        self.docs.append(code)
 
     def do_mapping_header(self, mapping):
         members = mapping.getElementsByTagNameNS(NS_TP, 'member')
