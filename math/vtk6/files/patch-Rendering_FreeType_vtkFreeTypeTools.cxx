--- Rendering/FreeType/vtkFreeTypeTools.cxx.orig	2020-10-26 19:28:43 UTC
+++ Rendering/FreeType/vtkFreeTypeTools.cxx
@@ -280,7 +280,7 @@ FTC_CMapCache* vtkFreeTypeTools::GetCMapCache()
 }
 
 //----------------------------------------------------------------------------
-FT_CALLBACK_DEF(FT_Error)
+static FT_Error
 vtkFreeTypeToolsFaceRequester(FTC_FaceID face_id,
                               FT_Library lib,
                               FT_Pointer request_data,
