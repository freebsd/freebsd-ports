--- Gato.py.orig	Wed May 16 13:16:55 2001
+++ Gato.py	Mon Sep  3 12:26:21 2001
@@ -38,7 +38,6 @@
 import bdb
 import whrandom
 import re 
-import regsub
 import string
 import StringIO
 import tokenize
@@ -49,13 +48,13 @@
 from ScrolledText import ScrolledText
 
 
-from Graph import Graph
-from GraphUtil import *
-from GraphDisplay import GraphDisplayToplevel
-from GatoUtil import *
-from GatoGlobals import *
-from GatoDialogs import AboutBox, SplashScreen, HTMLViewer
-import GatoIcons
+from Gato.Graph import Graph
+from Gato.GraphUtil import *
+from Gato.GraphDisplay import GraphDisplayToplevel
+from Gato.GatoUtil import *
+from Gato.GatoGlobals import *
+from Gato.GatoDialogs import AboutBox, SplashScreen, HTMLViewer
+from Gato import GatoIcons
 
 # put someplace else
 def WMExtrasGeometry(window):
@@ -67,7 +66,7 @@
 
         NOTE: Does not work with tk8.0 style menus, since those are
               handled by WM (according to Tk8.1 docs) """
-    g = regsub.split(window.geometry(),"+") 
+    g = re.split("\+", window.geometry()) 
     trueRootx = string.atoi(g[1]) 
     trueRooty = string.atoi(g[2])
     
@@ -1159,11 +1158,11 @@
 	    self.algoGlobals['A'] = self.GUI.graphDisplay
 	# XXX
 	# explictely loading packages we want to make available to the algorithm
-	modules = ['DataStructures', 
-		   'AnimatedDataStructures', 
-		   'AnimatedAlgorithms',
-		   'GraphUtil',
-		   'GatoUtil']
+	modules = ['Gato.DataStructures', 
+		   'Gato.AnimatedDataStructures', 
+		   'Gato.AnimatedAlgorithms',
+		   'Gato.GraphUtil',
+		   'Gato.GatoUtil']
 
 	for m in modules:
 	    exec("from %s import *" % m, self.algoGlobals, self.algoGlobals)
