--- src/tools/io/io_grid_image/grid_to_kml.cpp.orig	2018-05-03 05:29:35 UTC
+++ src/tools/io/io_grid_image/grid_to_kml.cpp
@@ -504,7 +504,7 @@ bool CGrid_from_KML::On_Execute(void)
 
 	if( !KML.Load(&File) )
 	{
-		Error_Fmt("%s [%s]", _TL("failed to load file"), File.wc_str());
+		Error_Fmt("%s [%s]", _TL("failed to load file"), File.wx_str());
 
 		return( false );
 	}
@@ -582,11 +582,11 @@ bool CGrid_from_KML::Load_Overlay(const SG_Char *Dir, 
 	}
 
 	CSG_Data_Manager	Data;
-	CSG_String			FullPath = fn.GetFullPath().wc_str();
+	CSG_String			FullPath = fn.GetFullPath().wx_str();
 
 	if( !Data.Add(FullPath) || !Data.Get_Grid_System(0) || !Data.Get_Grid_System(0)->Get(0) )
 	{
-		Error_Fmt("%s: %s", _TL("failed to load KML ground overlay icon"), fn.GetFullPath().wc_str());
+		Error_Fmt("%s: %s", _TL("failed to load KML ground overlay icon"), fn.GetFullPath().wx_str());
 	}
 
 	//-----------------------------------------------------
