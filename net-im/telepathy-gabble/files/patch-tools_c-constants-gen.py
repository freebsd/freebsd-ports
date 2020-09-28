--- tools/c-constants-gen.py.orig	2014-05-07 14:28:43 UTC
+++ tools/c-constants-gen.py
@@ -12,7 +12,7 @@ class Generator(object):
         self.prefix = prefix + '_'
         self.spec = get_by_path(dom, "spec")[0]
 
-	self.output_base = output_base
+        self.output_base = output_base
         self.__header = []
         self.__docs = []
 
@@ -25,10 +25,10 @@ class Generator(object):
         file_set_contents(self.output_base + '-gtk-doc.h', ''.join(self.__docs))
 
     def write(self, code):
-        self.__header.append(code.encode('utf-8'))
+        self.__header.append(code)
 
     def d(self, code):
-        self.__docs.append(code.encode('utf-8'))
+        self.__docs.append(code)
 
     # Header
     def do_header(self):
