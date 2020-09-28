--- tools/libtpcodegen.py.orig	2020-09-23 16:17:54 UTC
+++ tools/libtpcodegen.py
@@ -21,6 +21,7 @@ please make any changes there.
 # Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 
 import os
+import sys
 from string import ascii_letters, digits
 
 
@@ -28,6 +29,20 @@ NS_TP = "http://telepathy.freedesktop.org/wiki/DbusSpe
 
 _ASCII_ALNUM = ascii_letters + digits
 
+if sys.version_info[0] >= 3:
+    def u(s):
+        """Return s, which must be a str literal with no non-ASCII characters.
+        This is like a more restricted form of the Python 2 u'' syntax.
+        """
+        return s.encode('ascii').decode('ascii')
+else:
+    def u(s):
+        """Return a Unicode version of s, which must be a str literal
+        (a bytestring) in which each byte is an ASCII character.
+        This is like a more restricted form of the u'' syntax.
+        """
+        return s.decode('ascii')
+
 def file_set_contents(filename, contents):
     try:
         os.remove(filename)
@@ -38,13 +53,15 @@ def file_set_contents(filename, contents):
     except OSError:
         pass
 
-    open(filename + '.tmp', 'w').write(contents)
+    open(filename + '.tmp', 'wb').write(contents)
     os.rename(filename + '.tmp', filename)
 
 def cmp_by_name(node1, node2):
     return cmp(node1.getAttributeNode("name").nodeValue,
                node2.getAttributeNode("name").nodeValue)
 
+def key_by_name(node):
+    return node.getAttributeNode("name").nodeValue
 
 def escape_as_identifier(identifier):
     """Escape the given string to be a valid D-Bus object path or service
@@ -168,6 +185,9 @@ class _SignatureIter:
         self.remaining = string
 
     def next(self):
+        return self.__next__()
+
+    def __next__(self):
         if self.remaining == '':
             raise StopIteration
 
