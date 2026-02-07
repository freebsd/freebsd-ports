--- core/OOXML/Binary/Sheets/Reader/ChartFromToBinary.cpp.orig	2025-08-02 18:33:34 UTC
+++ core/OOXML/Binary/Sheets/Reader/ChartFromToBinary.cpp
@@ -10121,7 +10121,7 @@ namespace BinXlsxRW
 			WriteCT_String(*oVal.m_gapDepth);
 			m_oBcw.WriteItemEnd(nCurPos);
 		}
-		if (NULL != oVal.m_shape.IsInit())
+		if (0 != oVal.m_shape.IsInit())
 		{
 			int nCurPos = m_oBcw.WriteItemStart(c_oserct_bar3dchartSHAPE);
 			WriteCT_Shape(*oVal.m_shape);
