--- Gred.py	Fri Jan 20 15:15:55 2006
+++ Gred.py	Wed Mar  8 12:28:28 2006
@@ -1,4 +1,4 @@
-#!/usr/bin/env python2.3
+#!/usr/bin/env python
 ################################################################################
 #
 #       This file is part of Gato (Graph Animation Toolbox) 
@@ -34,17 +34,17 @@
 #             last change by $Author: schliep $.
 #
 ################################################################################
-from GatoGlobals import *
-import GatoGlobals # Needed for help viewer.XXX
-from Graph import Graph
-from DataStructures import EdgeWeight, VertexWeight
-from GraphUtil import OpenCATBoxGraph, OpenGMLGraph, OpenDotGraph, SaveCATBoxGraph, WeightedGraphInformer
-from GraphEditor import GraphEditor
+from Gato.GatoGlobals import *
+import Gato.GatoGlobals # Needed for help viewer.XXX
+from Gato.Graph import Graph
+from Gato.DataStructures import EdgeWeight, VertexWeight
+from Gato.GraphUtil import OpenCATBoxGraph, OpenGMLGraph, OpenDotGraph, SaveCATBoxGraph, WeightedGraphInformer
+from Gato.GraphEditor import GraphEditor
 from Tkinter import *
 import tkFont
-from GatoUtil import stripPath, extension, gatoPath
-import GatoDialogs
-import GatoIcons
+from Gato.GatoUtil import stripPath, extension, gatoPath
+from Gato import GatoDialogs
+from Gato import GatoIcons
 from ScrolledText import *
 
 from tkFileDialog import askopenfilename, asksaveasfilename
@@ -55,7 +55,7 @@
 import sys
 import os
 
-import GraphCreator, Embedder
+from Gato import GraphCreator, Embedder
 
 class GredSplashScreen(GatoDialogs.SplashScreen):
 
@@ -843,7 +843,7 @@
 ##    globals()['gVertexRadius'] = 12
 ##    globals()['gVertexFrameWidth'] = 0
 ##    globals()['gEdgeWidth'] = 2
-    GatoGlobals.cVertexDefault = '#000099'
+    Gato.GatoGlobals.cVertexDefault = '#000099'
     ##    globals()['cEdgeDefault'] = '#999999'
     ##    globals()['cLabelDefault'] = 'white'
     
