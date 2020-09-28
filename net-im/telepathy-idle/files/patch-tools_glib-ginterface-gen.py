--- tools/glib-ginterface-gen.py.orig	2020-09-28 19:59:50 UTC
+++ tools/glib-ginterface-gen.py
@@ -22,6 +22,7 @@
 # License along with this library; if not, write to the Free Software
 # Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 
+import functools
 import sys
 import os.path
 import xml.dom.minidom
@@ -85,18 +86,12 @@ class Generator(object):
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
@@ -733,7 +728,7 @@ class Generator(object):
 
     def __call__(self):
         nodes = self.dom.getElementsByTagName('node')
-        nodes.sort(cmp_by_name)
+        nodes.sort(key=functools.cmp_to_key(cmp_by_name))
 
         self.h('#include <glib-object.h>')
         self.h('#include <dbus/dbus-glib.h>')
@@ -768,7 +763,7 @@ class Generator(object):
         file_set_contents(self.basename + '-gtk-doc.h', '\n'.join(self.__docs))
 
 def cmdline_error():
-    print """\
+    print ("""\
 usage:
     gen-ginterface [OPTIONS] xmlfile Prefix_
 options:
@@ -788,7 +783,7 @@ options:
             void symbol (DBusGMethodInvocation *context)
         and return some sort of "not implemented" error via
             dbus_g_method_return_error (context, ...)
-"""
+""")
     sys.exit(1)
 
 
