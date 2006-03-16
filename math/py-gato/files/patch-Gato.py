--- Gato.py	Fri Jan 20 15:15:55 2006
+++ Gato.py	Wed Mar  8 15:23:21 2006
@@ -1,4 +1,4 @@
-#!/usr/bin/env python2.3
+#!/usr/bin/env python
 ################################################################################
 #
 #       This file is part of Gato (Graph Animation Toolbox) 
@@ -48,22 +48,22 @@
 import tkFont
 import copy
 
-import Gred
+from Gato import Gred
 
 from Tkinter import *
 from tkFileDialog import askopenfilename, asksaveasfilename
 from tkMessageBox import askokcancel, showerror, askyesno
 from ScrolledText import ScrolledText
-from GatoConfiguration import GatoConfiguration
-from Graph import Graph
-from GraphUtil import *
-from GraphDisplay import GraphDisplayToplevel
-from GatoUtil import *
-from GatoGlobals import *
-from GatoDialogs import AboutBox, SplashScreen, HTMLViewer
-import GatoIcons
-import GatoSystemConfiguration
-from AnimationHistory import AnimationHistory
+from Gato.GatoConfiguration import GatoConfiguration
+from Gato.Graph import Graph
+from Gato.GraphUtil import *
+from Gato.GraphDisplay import GraphDisplayToplevel
+from Gato.GatoUtil import *
+from Gato.GatoGlobals import *
+from Gato.GatoDialogs import AboutBox, SplashScreen, HTMLViewer
+from Gato import GatoIcons
+from Gato import GatoSystemConfiguration
+from Gato.AnimationHistory import AnimationHistory
 
 # put someplace else
 def WMExtrasGeometry(window):
@@ -1419,11 +1419,11 @@
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
