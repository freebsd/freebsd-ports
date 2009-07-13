--- Gato.py	Wed Jul 08 22:14:29 2009 +0900
+++ Gato.py	Wed Jul 08 22:16:07 2009 +0900
@@ -1,4 +1,4 @@
-#!/usr/bin/env python2.3
+#!/usr/bin/env python
 ################################################################################
 #
 #       This file is part of Gato (Graph Animation Toolbox) 
@@ -1590,11 +1590,11 @@
             self.algoGlobals['A'] = self.GUI.graphDisplay
             # XXX
             # explictely loading packages we want to make available to the algorithm
-        modules = ['DataStructures', 
-                   'AnimatedDataStructures', 
-                   'AnimatedAlgorithms',
-                   'GraphUtil',
-                   'GatoUtil']
+        modules = ['Gato.DataStructures', 
+                   'Gato.AnimatedDataStructures', 
+                   'Gato.AnimatedAlgorithms',
+                   'Gato.GraphUtil',
+                   'Gato.GatoUtil']
         
         for m in modules:
             exec("from %s import *" % m, self.algoGlobals, self.algoGlobals)
