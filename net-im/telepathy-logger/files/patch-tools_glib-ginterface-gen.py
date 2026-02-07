--- tools/glib-ginterface-gen.py.orig	2020-09-23 16:17:54 UTC
+++ tools/glib-ginterface-gen.py
@@ -26,8 +26,8 @@ import sys
 import os.path
 import xml.dom.minidom
 
-from libtpcodegen import file_set_contents
-from libglibcodegen import Signature, type_to_gtype, cmp_by_name, \
+from libtpcodegen import file_set_contents, key_by_name, u
+from libglibcodegen import Signature, type_to_gtype, \
         NS_TP, dbus_gutils_wincaps_to_uscore
 
 
@@ -85,18 +85,12 @@ class Generator(object):
         self.allow_havoc = allow_havoc
 
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
 
     def do_node(self, node):
@@ -733,7 +727,7 @@ class Generator(object):
 
     def __call__(self):
         nodes = self.dom.getElementsByTagName('node')
-        nodes.sort(cmp_by_name)
+        nodes.sort(key=key_by_name)
 
         self.h('#include <glib-object.h>')
         self.h('#include <dbus/dbus-glib.h>')
@@ -763,12 +757,12 @@ class Generator(object):
 
         self.h('')
         self.b('')
-        file_set_contents(self.basename + '.h', '\n'.join(self.__header))
-        file_set_contents(self.basename + '.c', '\n'.join(self.__body))
-        file_set_contents(self.basename + '-gtk-doc.h', '\n'.join(self.__docs))
+        file_set_contents(self.basename + '.h', u('\n').join(self.__header).encode('utf-8'))
+        file_set_contents(self.basename + '.c', u('\n').join(self.__body).encode('utf-8'))
+        file_set_contents(self.basename + '-gtk-doc.h', u('\n').join(self.__docs).encode('utf-8'))
 
 def cmdline_error():
-    print """\
+    print("""\
 usage:
     gen-ginterface [OPTIONS] xmlfile Prefix_
 options:
@@ -788,7 +782,7 @@ options:
             void symbol (DBusGMethodInvocation *context)
         and return some sort of "not implemented" error via
             dbus_g_method_return_error (context, ...)
-"""
+""")
     sys.exit(1)
 
 
