--- moose-gui/mgui.py.orig	2017-12-16 19:10:20 UTC
+++ moose-gui/mgui.py
@@ -44,6 +44,7 @@
 #
 
 # Code:
+import numpy.core.multiarray # doesn't work without it for some reason
 import imp
 import inspect
 import code
