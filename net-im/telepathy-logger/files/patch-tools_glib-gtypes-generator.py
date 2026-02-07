--- tools/glib-gtypes-generator.py.orig	2020-09-23 16:17:54 UTC
+++ tools/glib-gtypes-generator.py
@@ -23,7 +23,7 @@
 import sys
 import xml.dom.minidom
 
-from libtpcodegen import file_set_contents
+from libtpcodegen import file_set_contents, u
 from libglibcodegen import escape_as_identifier, \
                            get_docstring, \
                            NS_TP, \
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
@@ -292,9 +292,9 @@ class GTypesGenerator(object):
             self.c('  return t;\n')
             self.c('}\n\n')
 
-        file_set_contents(self.output + '.h', ''.join(self.header))
-        file_set_contents(self.output + '-body.h', ''.join(self.body))
-        file_set_contents(self.output + '-gtk-doc.h', ''.join(self.docs))
+        file_set_contents(self.output + '.h', u('').join(self.header).encode('utf-8'))
+        file_set_contents(self.output + '-body.h', u('').join(self.body).encode('utf-8'))
+        file_set_contents(self.output + '-gtk-doc.h', u('').join(self.docs).encode('utf-8'))
 
 if __name__ == '__main__':
     argv = sys.argv[1:]
