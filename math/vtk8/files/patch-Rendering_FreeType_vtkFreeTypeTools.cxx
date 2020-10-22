--- Rendering/FreeType/vtkFreeTypeTools.cxx.orig	2020-10-22 10:20:24 UTC
+++ Rendering/FreeType/vtkFreeTypeTools.cxx
@@ -387,7 +387,7 @@ FTC_CMapCache* vtkFreeTypeTools::GetCMapCache()
 }
 
 //----------------------------------------------------------------------------
-FT_CALLBACK_DEF(FT_Error)
+static FT_Error
 vtkFreeTypeToolsFaceRequester(FTC_FaceID face_id,
                               FT_Library lib,
                               FT_Pointer request_data,
