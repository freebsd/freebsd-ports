--- Gred.py.orig	Wed May 16 13:16:58 2001
+++ Gred.py	Mon Sep  3 12:01:13 2001
@@ -31,16 +31,16 @@
 #             last change by $Author: schliep $.
 #
 ################################################################################
-from Graph import Graph
-from DataStructures import EdgeWeight, VertexWeight
-from GraphUtil import OpenCATBoxGraph, OpenGMLGraph, SaveCATBoxGraph, WeightedGraphInformer
-from GraphEditor import GraphEditor
+from Gato.Graph import Graph
+from Gato.DataStructures import EdgeWeight, VertexWeight
+from Gato.GraphUtil import OpenCATBoxGraph, OpenGMLGraph, SaveCATBoxGraph, WeightedGraphInformer
+from Gato.GraphEditor import GraphEditor
 from Tkinter import *
-from GatoUtil import stripPath, extension, gatoPath
-from GatoGlobals import *
-import GatoDialogs
-import GatoGlobals
-import GatoIcons
+from Gato.GatoUtil import stripPath, extension, gatoPath
+from Gato.GatoGlobals import *
+from Gato import GatoDialogs
+from Gato import GatoGlobals
+from Gato import GatoIcons
 from ScrolledText import *
 
 from tkFileDialog import askopenfilename, asksaveasfilename
@@ -51,7 +51,8 @@
 import sys
 import os
 
-import GraphCreator, Embedder
+from Gato import GraphCreator
+from Gato import Embedder
 
 class GredSplashScreen(GatoDialogs.SplashScreen):
 
