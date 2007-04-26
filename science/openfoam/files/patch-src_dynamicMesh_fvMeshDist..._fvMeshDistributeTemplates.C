--- src/dynamicMesh/fvMeshDistribute/fvMeshDistributeTemplates.C.orig	Tue Mar 20 21:35:42 2007
+++ src/dynamicMesh/fvMeshDistribute/fvMeshDistributeTemplates.C	Mon Apr 16 23:09:38 2007
@@ -307,8 +307,10 @@
 
         // Send all fieldNames. This has to be exactly the same set as is
         // being received!
+
+	// FreeBSD: following patch only for gcc-3.4, to be removed with gcc-4.2
         const fldType& fld =
-            subsetter.baseMesh().lookupObject<fldType>(fieldNames[i]);
+            subsetter.baseMesh().template lookupObject<fldType>(fieldNames[i]);
 
         tmp<fldType> tsubfld = subsetter.interpolate(fld);
 
