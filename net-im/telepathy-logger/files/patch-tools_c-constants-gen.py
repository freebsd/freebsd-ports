--- tools/c-constants-gen.py.orig	2020-09-23 16:17:54 UTC
+++ tools/c-constants-gen.py
@@ -3,7 +3,7 @@
 from sys import argv, stdout, stderr
 import xml.dom.minidom
 
-from libtpcodegen import file_set_contents
+from libtpcodegen import file_set_contents, u
 from libglibcodegen import NS_TP, get_docstring, \
         get_descendant_text, get_by_path
 
@@ -12,7 +12,7 @@ class Generator(object):
         self.prefix = prefix + '_'
         self.spec = get_by_path(dom, "spec")[0]
 
-	self.output_base = output_base
+        self.output_base = output_base
         self.__header = []
         self.__docs = []
 
@@ -21,14 +21,14 @@ class Generator(object):
         self.do_body()
         self.do_footer()
 
-        file_set_contents(self.output_base + '.h', ''.join(self.__header))
-        file_set_contents(self.output_base + '-gtk-doc.h', ''.join(self.__docs))
+        file_set_contents(self.output_base + '.h', u('').join(self.__header).encode('utf-8'))
+        file_set_contents(self.output_base + '-gtk-doc.h', u('').join(self.__docs).encode('utf-8'))
 
     def write(self, code):
-        self.__header.append(code.encode('utf-8'))
+        self.__header.append(code)
 
     def d(self, code):
-        self.__docs.append(code.encode('utf-8'))
+        self.__docs.append(code)
 
     # Header
     def do_header(self):
