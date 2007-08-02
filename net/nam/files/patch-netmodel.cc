--- netmodel.cc.orig	2007-08-02 14:44:09.000000000 +0200
+++ netmodel.cc	2007-08-02 14:47:11.000000000 +0200
@@ -308,7 +308,7 @@
 	Tcl_HashEntry *he = Tcl_FindHashEntry(addrHash_, (const char *)addr);
 	if (he == NULL)
 		return -1;
-	return (int)Tcl_GetHashValue(he);
+	return (intptr_t)Tcl_GetHashValue(he);
 }
 
 //----------------------------------------------------------------------
@@ -2761,7 +2761,7 @@
 	Tcl_HashEntry *he = Tcl_FindHashEntry(objnameHash_, n);
 	if (he == NULL)
 		return -1;
-	return (int)Tcl_GetHashValue(he);
+	return (intptr_t)Tcl_GetHashValue(he);
 #undef STATIC_NAMELEN
 }
 
