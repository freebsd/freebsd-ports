--- src/sphinx_inline_tabs/_impl.py.orig	2021-04-11 11:03:11 UTC
+++ src/sphinx_inline_tabs/_impl.py
@@ -1,7 +1,11 @@
 """The actual implementation."""
 
 import itertools
-from typing import List, Literal
+from typing import List
+try:
+    from typing import Literal
+except ImportError:
+    from typing_extensions import Literal
 
 from docutils import nodes
 from docutils.parsers.rst import directives
