--- Gato.py.dist	Thu Dec 18 00:34:01 2003
+++ Gato.py	Thu Dec 18 00:35:50 2003
@@ -54,15 +54,15 @@
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
+from Gato.GatoConfiguration import GatoConfiguration
+from Gato.Graph import Graph
+from Gato.GraphUtil import *
+from Gato.GraphDisplay import GraphDisplayToplevel
+from Gato.GatoUtil import *
+from Gato.GatoGlobals import *
+from Gato.GatoDialogs import AboutBox, SplashScreen, HTMLViewer
+from Gato import GatoIcons
+import Gato.GatoSystemConfiguration
 
 # put someplace else
 def WMExtrasGeometry(window):
@@ -1397,11 +1397,11 @@
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
