--- cmake/modules/FindDEAL_II_OPENCASCADE.cmake.orig	2024-02-01 02:26:09 UTC
+++ cmake/modules/FindDEAL_II_OPENCASCADE.cmake
@@ -67,11 +67,19 @@ endif()
 endif()
 
 # These seem to be pretty much the only required ones.
-set(_opencascade_libraries
-  TKBO TKBool TKBRep TKernel TKFeat TKFillet TKG2d TKG3d TKGeomAlgo
-  TKGeomBase TKHLR TKIGES TKMath TKMesh TKOffset TKPrim TKShHealing TKSTEP
-  TKSTEPAttr TKSTEPBase TKSTEP209 TKSTL TKTopAlgo TKXSBase
-  )
+if(OPENCASCADE_VERSION AND OPENCASCADE_VERSION VERSION_GREATER_EQUAL "7.8.0")
+  set(_opencascade_libraries
+    TKBO TKBool TKBRep TKernel TKFeat TKFillet TKG2d TKG3d TKGeomAlgo
+    TKGeomBase TKHLR TKDEIGES TKMath TKMesh TKOffset TKPrim TKShHealing TKDESTEP
+    TKDESTL TKTopAlgo TKXSBase
+    )
+    else()
+  set(_opencascade_libraries
+    TKBO TKBool TKBRep TKernel TKFeat TKFillet TKG2d TKG3d TKGeomAlgo
+    TKGeomBase TKHLR TKIGES TKMath TKMesh TKOffset TKPrim TKShHealing TKSTEP
+    TKSTEPAttr TKSTEPBase TKSTEP209 TKSTL TKTopAlgo TKXSBase
+    )
+endif()
 
 set(_libraries "")
 foreach(_library ${_opencascade_libraries})
