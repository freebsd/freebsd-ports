------------------------------------------------------------------------
r1807005 | scantor | 2017-09-01 22:42:20 +0200 (Fri, 01 Sep 2017) | 1 line

Cleanup, reverse double negatives in Xalan code paths

Index: xsec/tools/checksig/InteropResolver.cpp
===================================================================
--- xsec/tools/checksig/InteropResolver.cpp	(revision 1807004)
+++ xsec/tools/checksig/InteropResolver.cpp	(revision 1807005)
@@ -648,7 +648,7 @@
 
 	}
 
-	return false;
+	return NULL;
 
 }
 

------------------------------------------------------------------------
