--- lib/python/RestrictedPython/tests/verify.py.orig	Thu Jun 17 13:39:24 2004
+++ lib/python/RestrictedPython/tests/verify.py	Thu Jun 17 13:39:41 2004
@@ -21,6 +21,7 @@
 function.
 """
 
+from __future__ import generators
 import dis
 import types
 
