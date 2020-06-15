--- src/tools/projection/pj_proj4/globe_gores.cpp.orig	2020-05-24 11:21:37 UTC
+++ src/tools/projection/pj_proj4/globe_gores.cpp
@@ -207,7 +207,7 @@ bool CGlobe_Gores::Add_Gore(int iGore, int nGores)
 
 		SG_Get_Tool_Library_Manager().Delete_Tool(pTool);
 
-		return( NULL );
+		return( false );
 	}
 
 	CSG_Grid	*pGore	= pTool->Get_Parameter("GRID")->asGrid();
