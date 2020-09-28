--- tools/glib-ginterface-gen.py.orig	2011-08-16 11:04:41 UTC
+++ tools/glib-ginterface-gen.py
@@ -26,7 +26,7 @@ import sys
 import os.path
 import xml.dom.minidom
 
-from libglibcodegen import Signature, type_to_gtype, cmp_by_name, \
+from libglibcodegen import Signature, type_to_gtype, \
         camelcase_to_lower, NS_TP, dbus_gutils_wincaps_to_uscore, \
         signal_to_marshal_name, method_to_glue_marshal_name
 
@@ -620,7 +620,7 @@ class Generator(object):
         self.b('')
 
         nodes = self.dom.getElementsByTagName('node')
-        nodes.sort(cmp_by_name)
+        nodes.sort(key=lambda node : node.getAttributeNode('name').nodeValue)
 
         for node in nodes:
             self.do_node(node)
@@ -639,7 +639,7 @@ class Generator(object):
 
 
 def cmdline_error():
-    print """\
+    print("""\
 usage:
     gen-ginterface [OPTIONS] xmlfile Prefix_
 options:
@@ -659,7 +659,7 @@ options:
             void symbol (DBusGMethodInvocation *context)
         and return some sort of "not implemented" error via
             dbus_g_method_return_error (context, ...)
-"""
+""")
     sys.exit(1)
 
 
