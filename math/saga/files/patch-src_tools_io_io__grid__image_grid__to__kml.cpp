grid_to_kml.cpp: In member function 'bool CGrid_from_KML::Load_Overlay(const wchar_t*, const CSG_MetaData&)':
grid_to_kml.cpp:585:49: error: conversion from 'const wxScopedWCharBuffer {aka const wxScopedCharTypeBuffer<wchar_t>}' to non-scalar type 'CSG_String' requested
  CSG_String   FullPath = fn.GetFullPath().wc_str();
                          ~~~~~~~~~~~~~~~~~~~~~~~^~

--- src/tools/io/io_grid_image/grid_to_kml.cpp.orig	2017-06-21 13:50:57 UTC
+++ src/tools/io/io_grid_image/grid_to_kml.cpp
@@ -582,7 +582,7 @@ bool CGrid_from_KML::Load_Overlay(const SG_Char *Dir, 
 	}
 
 	CSG_Data_Manager	Data;
-	CSG_String			FullPath = fn.GetFullPath().wc_str();
+	CSG_String		FullPath = static_cast<const wchar_t*>(fn.GetFullPath().wc_str());
 
 	if( !Data.Add(FullPath) || !Data.Get_Grid_System(0) || !Data.Get_Grid_System(0)->Get(0) )
 	{
