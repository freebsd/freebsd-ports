--- tools/glib-client-gen.py.orig	2020-09-23 16:17:54 UTC
+++ tools/glib-client-gen.py
@@ -27,8 +27,8 @@ import os.path
 import xml.dom.minidom
 from getopt import gnu_getopt
 
-from libtpcodegen import file_set_contents
-from libglibcodegen import Signature, type_to_gtype, cmp_by_name, \
+from libtpcodegen import file_set_contents, key_by_name, u
+from libglibcodegen import Signature, type_to_gtype, \
         get_docstring, xml_escape, get_deprecated
 
 
@@ -74,18 +74,12 @@ class Generator(object):
         self.guard = opts.get('--guard', None)
 
     def h(self, s):
-        if isinstance(s, unicode):
-            s = s.encode('utf-8')
         self.__header.append(s)
 
     def b(self, s):
-        if isinstance(s, unicode):
-            s = s.encode('utf-8')
         self.__body.append(s)
 
     def d(self, s):
-        if isinstance(s, unicode):
-            s = s.encode('utf-8')
         self.__docs.append(s)
 
     def get_iface_quark(self):
@@ -1187,7 +1181,7 @@ class Generator(object):
         self.b('')
 
         nodes = self.dom.getElementsByTagName('node')
-        nodes.sort(cmp_by_name)
+        nodes.sort(key=key_by_name)
 
         for node in nodes:
             self.do_interface(node)
@@ -1240,9 +1234,9 @@ class Generator(object):
             self.h('#endif /* defined (%s) */' % self.guard)
             self.h('')
 
-        file_set_contents(self.basename + '.h', '\n'.join(self.__header))
-        file_set_contents(self.basename + '-body.h', '\n'.join(self.__body))
-        file_set_contents(self.basename + '-gtk-doc.h', '\n'.join(self.__docs))
+        file_set_contents(self.basename + '.h', u('\n').join(self.__header).encode('utf-8'))
+        file_set_contents(self.basename + '-body.h', u('\n').join(self.__body).encode('utf-8'))
+        file_set_contents(self.basename + '-gtk-doc.h', u('\n').join(self.__docs).encode('utf-8'))
 
 def types_to_gtypes(types):
     return [type_to_gtype(t)[1] for t in types]
