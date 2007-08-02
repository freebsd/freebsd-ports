--- group.cc.orig	2007-08-02 14:51:34.000000000 +0200
+++ group.cc	2007-08-02 14:51:56.000000000 +0200
@@ -81,7 +81,7 @@
 	for (he = Tcl_FirstHashEntry(nodeHash_, &hs);
 	     he != NULL;
 	     he = Tcl_NextHashEntry(&hs), i++) 
-		mbrs[i] = (int) Tcl_GetHashValue(he);
+		mbrs[i] = (intptr_t) Tcl_GetHashValue(he);
 }
 
 void Group::draw(View * nv, double now) {
