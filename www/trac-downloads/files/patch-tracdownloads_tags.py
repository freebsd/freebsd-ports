--- tracdownloads/tags.py.orig	2010-10-12 12:42:10 UTC
+++ tracdownloads/tags.py
@@ -1,11 +1,5 @@
 # -*- coding: utf-8 -*-
 
-# Deprecated as for Python 2.6.
-try:
-    import sets
-except:
-    pass
-
 # Trac imports.
 from trac.core import *
 from trac.resource import Resource
