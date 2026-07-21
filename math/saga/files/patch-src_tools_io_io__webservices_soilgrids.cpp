--- src/tools/io/io_webservices/soilgrids.cpp.orig	2026-07-21 14:35:15 UTC
+++ src/tools/io/io_webservices/soilgrids.cpp
@@ -430,7 +430,7 @@ bool CSoilGrids_WebDAV::Get_Variable(int Variable, int
 			m_Attributes[0].Set_Value("depth.inverse",-CSoilGrids::Get_Depth_Center(Layer));
 		}
 
-		bResult = Get_Variable(Variable, Distribution, Layer) != NULL;
+		bResult = Get_Variable(Variable, Distribution, Layer);
 	}
 
 	//-----------------------------------------------------
