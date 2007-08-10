--- src/dynamicMesh/fvMeshDistribute/fvMeshDistributeTemplates.C.orig	Tue Jun 26 18:53:30 2007
+++ src/dynamicMesh/fvMeshDistribute/fvMeshDistributeTemplates.C	Sun Aug  5 18:01:13 2007
@@ -295,8 +295,10 @@
 
         // Send all fieldNames. This has to be exactly the same set as is
         // being received!
+
+	// FreeBSD: following patch only for gcc-3.4, to be removed with gcc-4.2
         const GeoField& fld =
-            subsetter.baseMesh().lookupObject<GeoField>(fieldNames[i]);
+            subsetter.baseMesh().template lookupObject<GeoField>(fieldNames[i]);
 
         tmp<GeoField> tsubfld = subsetter.interpolate(fld);
 
