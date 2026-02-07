--- core/OOXML/XlsxFormat/Chart/ChartSerialize.cpp.orig	2025-08-02 18:33:34 UTC
+++ core/OOXML/XlsxFormat/Chart/ChartSerialize.cpp
@@ -1282,7 +1282,7 @@ xmlns:c16r2=\"http://schemas.microsoft.com/office/draw
 		{
 			writer.WriteString(L"<");
 			writer.WriteString(sNodeName);
-			if (NULL != m_l.IsInit())
+			if (0 != m_l.IsInit())
 			{
 				WritingStringAttrDouble(L"l", *m_l);
 			}
