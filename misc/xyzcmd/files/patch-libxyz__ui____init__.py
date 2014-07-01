--- ./libxyz/ui/__init__.py.orig	2014-07-01 19:55:27.884601353 +0400
+++ ./libxyz/ui/__init__.py	2014-07-01 19:57:02.576866186 +0400
@@ -47,6 +47,8 @@
 )
 
 import urwid as lowui
+if int(lowui.__version__[0]) == 1:
+    lowui.escape.utf8decode = lambda x: x
 
 import display
 import align
