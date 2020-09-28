--- tools/glib-interfaces-gen.py.orig	2020-09-23 16:17:54 UTC
+++ tools/glib-interfaces-gen.py
@@ -3,7 +3,7 @@
 from sys import argv, stdout, stderr
 import xml.dom.minidom
 
-from libtpcodegen import file_set_contents
+from libtpcodegen import file_set_contents, u
 from libglibcodegen import NS_TP, get_docstring, \
         get_descendant_text, get_by_path
 
@@ -24,22 +24,22 @@ class Generator(object):
         self.spec = get_by_path(dom, "spec")[0]
 
     def h(self, code):
-        self.decls.append(code.encode('utf-8'))
+        self.decls.append(code)
 
     def c(self, code):
-        self.impls.append(code.encode('utf-8'))
+        self.impls.append(code)
 
     def d(self, code):
-        self.docs.append(code.encode('utf-8'))
+        self.docs.append(code)
 
     def __call__(self):
         for f in self.h, self.c:
             self.do_header(f)
         self.do_body()
 
-        file_set_contents(self.implfile, ''.join(self.impls))
-        file_set_contents(self.declfile, ''.join(self.decls))
-        file_set_contents(self.docfile, ''.join(self.docs))
+        file_set_contents(self.implfile, u('').join(self.impls).encode('utf-8'))
+        file_set_contents(self.declfile, u('').join(self.decls).encode('utf-8'))
+        file_set_contents(self.docfile, u('').join(self.docs).encode('utf-8'))
 
     # Header
     def do_header(self, f):
