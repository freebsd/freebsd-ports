--- Graph.py.orig	Wed May 16 13:16:57 2001
+++ Graph.py	Fri Aug 31 17:12:01 2001
@@ -31,7 +31,7 @@
 #
 ################################################################################
 
-from regsub import split
+from re import split
 from GatoGlobals import *
 from DataStructures import Point2D, VertexLabeling, EdgeLabeling, EdgeWeight
 from math import log
