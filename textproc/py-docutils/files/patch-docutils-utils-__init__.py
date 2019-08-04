Obtained from:  https://sourceforge.net/p/docutils/code/8294/

--- docutils/utils/__init__.py.orig	2019-04-07 08:08:42 UTC
+++ docutils/utils/__init__.py
@@ -18,6 +18,7 @@ import warnings
 import unicodedata
 from docutils import ApplicationError, DataError, __version_info__
 from docutils import nodes
+from docutils.nodes import unescape
 import docutils.io
 from docutils.utils.error_reporting import ErrorOutput, SafeString
 
@@ -576,18 +577,7 @@ def escape2null(text):
         parts.append('\x00' + text[found+1:found+2])
         start = found + 2               # skip character after escape
 
-def unescape(text, restore_backslashes=False, respect_whitespace=False):
-    """
-    Return a string with nulls removed or restored to backslashes.
-    Backslash-escaped spaces are also removed.
-    """
-    # `respect_whitespace` is ignored (since introduction 2016-12-16)
-    if restore_backslashes:
-        return text.replace('\x00', '\\')
-    else:
-        for sep in ['\x00 ', '\x00\n', '\x00']:
-            text = ''.join(text.split(sep))
-        return text
+# `unescape` definition moved to `nodes` to avoid circular import dependency.
 
 def split_escaped_whitespace(text):
     """
