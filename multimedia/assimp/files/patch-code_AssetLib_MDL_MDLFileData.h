--- code/AssetLib/MDL/MDLFileData.h.orig	2023-10-16 03:31:18 UTC
+++ code/AssetLib/MDL/MDLFileData.h
@@ -603,7 +603,7 @@ struct Vertex_MDL7
     union {
         uint8_t norm162index;
         float norm[3];
-    };
+    } PACK_STRUCT;
 } PACK_STRUCT;
 
 // -------------------------------------------------------------------------------------
