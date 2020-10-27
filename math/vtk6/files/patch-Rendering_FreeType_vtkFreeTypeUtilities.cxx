--- Rendering/FreeType/vtkFreeTypeUtilities.cxx.orig	2020-10-26 19:35:51 UTC
+++ Rendering/FreeType/vtkFreeTypeUtilities.cxx
@@ -325,7 +325,7 @@ void vtkFreeTypeUtilities::MapIdToTextProperty(unsigne
 
 //----------------------------------------------------------------------------
 #ifdef VTK_FREETYPE_CACHING_SUPPORTED
-FT_CALLBACK_DEF(FT_Error)
+static FT_Error
 vtkFreeTypeUtilitiesFaceRequester(FTC_FaceID face_id,
                                   FT_Library lib,
                                   FT_Pointer request_data,
