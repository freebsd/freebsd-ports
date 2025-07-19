--- src/tools/imagery/imagery_tools/sentinel_3_scene_import.cpp.orig	2025-07-14 07:08:06 UTC
+++ src/tools/imagery/imagery_tools/sentinel_3_scene_import.cpp
@@ -371,7 +371,7 @@ bool CSentinel_3_Scene_Import::Load_Coordinates(const 
 	{
 		Error_Fmt("%s [%s]", _TL("file does not exist"), Directory.c_str());
 
-		return( NULL );
+		return( false );
 	}
 
 	Process_Set_Text("%s: %s", _TL("loading"), Name.c_str());
