--- tools/glib-ginterface-gen.py.orig	2014-05-07 14:28:02 UTC
+++ tools/glib-ginterface-gen.py
@@ -27,7 +27,7 @@ import os.path
 import xml.dom.minidom
 
 from libtpcodegen import file_set_contents
-from libglibcodegen import Signature, type_to_gtype, cmp_by_name, \
+from libglibcodegen import Signature, type_to_gtype, \
         NS_TP, dbus_gutils_wincaps_to_uscore
 
 
@@ -85,18 +85,18 @@ class Generator(object):
         self.allow_havoc = allow_havoc
 
     def h(self, s):
-        if isinstance(s, unicode):
-            s = s.encode('utf-8')
+        if isinstance(s, bytes):
+            s = str(s, 'ascii')
         self.__header.append(s)
 
     def b(self, s):
-        if isinstance(s, unicode):
-            s = s.encode('utf-8')
+        if isinstance(s, bytes):
+            s = str(s, 'ascii')
         self.__body.append(s)
 
     def d(self, s):
-        if isinstance(s, unicode):
-            s = s.encode('utf-8')
+        if isinstance(s, bytes):
+            s = str(s, 'ascii')
         self.__docs.append(s)
 
     def do_node(self, node):
@@ -733,7 +733,7 @@ class Generator(object):
 
     def __call__(self):
         nodes = self.dom.getElementsByTagName('node')
-        nodes.sort(cmp_by_name)
+        nodes.sort(key=lambda node : node.getAttributeNode('name').nodeValue)
 
         self.h('#include <glib-object.h>')
         self.h('#include <dbus/dbus-glib.h>')
@@ -766,7 +766,7 @@ class Generator(object):
         file_set_contents(self.basename + '-gtk-doc.h', '\n'.join(self.__docs))
 
 def cmdline_error():
-    print """\
+    print("""\
 usage:
     gen-ginterface [OPTIONS] xmlfile Prefix_
 options:
@@ -786,7 +786,7 @@ options:
             void symbol (DBusGMethodInvocation *context)
         and return some sort of "not implemented" error via
             dbus_g_method_return_error (context, ...)
-"""
+""")
     sys.exit(1)
 
 
