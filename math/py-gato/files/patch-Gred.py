--- Gred.py.orig	Fri Dec  5 13:08:46 2003
+++ Gred.py	Thu Dec 18 00:43:24 2003
@@ -34,17 +34,17 @@
 #             last change by $Author: schliep $.
 #
 ################################################################################
-from GatoGlobals import *
-import GatoGlobals # Needed for help viewer.XXX
-from Graph import Graph
-from DataStructures import EdgeWeight, VertexWeight
-from GraphUtil import OpenCATBoxGraph, OpenGMLGraph, SaveCATBoxGraph, WeightedGraphInformer
-from GraphEditor import GraphEditor
+from Gato.GatoGlobals import *
+import Gato.GatoGlobals # Needed for help viewer.XXX
+from Gato.Graph import Graph
+from Gato.DataStructures import EdgeWeight, VertexWeight
+from Gato.GraphUtil import OpenCATBoxGraph, OpenGMLGraph, SaveCATBoxGraph, WeightedGraphInformer
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
@@ -55,7 +55,8 @@
 import sys
 import os
 
-import GraphCreator, Embedder
+from Gato import GraphCreator
+from Gato import Embedder
 
 class GredSplashScreen(GatoDialogs.SplashScreen):
 
