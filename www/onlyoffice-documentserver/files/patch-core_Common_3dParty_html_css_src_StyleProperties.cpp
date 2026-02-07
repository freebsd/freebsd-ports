--- core/Common/3dParty/html/css/src/StyleProperties.cpp.orig	2024-08-28 20:31:59 UTC
+++ core/Common/3dParty/html/css/src/StyleProperties.cpp
@@ -816,7 +816,7 @@ namespace NSCSS
 		}
 
 		m_enType = ColorEmpty;
-		m_unLevel    = NULL;
+		m_unLevel    = 0;
 		m_bImportant = false;
 	}
 
@@ -2840,7 +2840,7 @@ namespace NSCSS
 	void CEnum::Clear()
 	{
 		m_oValue     = INT_MAX;
-		m_unLevel    = NULL;
+		m_unLevel    = 0;
 		m_bImportant = false;
 	}
 
