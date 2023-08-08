--- core/OOXML/Binary/Sheets/Reader/ChartFromToBinary.cpp.orig	2023-06-14 14:53:55.376306000 +0200
+++ core/OOXML/Binary/Sheets/Reader/ChartFromToBinary.cpp	2023-06-14 14:54:16.425588000 +0200
@@ -10010,7 +10010,7 @@ namespace BinXlsxRW
 			WriteCT_String(*oVal.m_gapDepth);
 			m_oBcw.WriteItemEnd(nCurPos);
 		}
-		if (NULL != oVal.m_shape.IsInit())
+		if (0 != oVal.m_shape.IsInit())
 		{
 			int nCurPos = m_oBcw.WriteItemStart(c_oserct_bar3dchartSHAPE);
 			WriteCT_Shape(*oVal.m_shape);
