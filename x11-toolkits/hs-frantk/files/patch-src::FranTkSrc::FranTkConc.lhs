--- FranTkSrc/FranTkConc.lhs.orig	Tue Sep 17 10:46:35 2002
+++ FranTkSrc/FranTkConc.lhs	Tue Sep 17 10:47:34 2002
@@ -6,6 +6,7 @@
 import Listener
 import Concurrent
 import IOExts
+import CVar
 
 addCVarListener :: CVar a -> Listener a -> GUI (IO ())
 addCVarListener cv l = 
