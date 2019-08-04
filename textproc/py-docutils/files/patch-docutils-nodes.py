Obtained from:  https://sourceforge.net/p/docutils/code/8294/

--- docutils/nodes.py.orig	2019-04-07 08:08:41 UTC
+++ docutils/nodes.py
@@ -29,8 +29,6 @@ import warnings
 import types
 import unicodedata
 
-import docutils.utils
-
 # ==============================
 #  Functional Node Base Classes
 # ==============================
@@ -322,6 +320,20 @@ def ensure_str(s):
         return s.encode('ascii', 'backslashreplace')
     return s
 
+# definition moved here from `utils` to avoid circular import dependency
+def unescape(text, restore_backslashes=False, respect_whitespace=False):
+    """
+    Return a string with nulls removed or restored to backslashes.
+    Backslash-escaped spaces are also removed.
+    """
+    # `respect_whitespace` is ignored (since introduction 2016-12-16)
+    if restore_backslashes:
+        return text.replace('\x00', '\\')
+    else:
+        for sep in ['\x00 ', '\x00\n', '\x00']:
+            text = ''.join(text.split(sep))
+        return text
+
 
 class Text(Node, reprunicode):
 
@@ -364,7 +376,7 @@ class Text(Node, reprunicode):
         return domroot.createTextNode(unicode(self))
 
     def astext(self):
-        return reprunicode(docutils.utils.unescape(self))
+        return reprunicode(unescape(self))
 
     # Note about __unicode__: The implementation of __unicode__ here,
     # and the one raising NotImplemented in the superclass Node had
