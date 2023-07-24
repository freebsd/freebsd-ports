--- core/OOXML/XlsxFormat/Chart/ChartSerialize.cpp.orig	2023-06-14 14:33:42.265435000 +0200
+++ core/OOXML/XlsxFormat/Chart/ChartSerialize.cpp	2023-06-14 14:33:54.354616000 +0200
@@ -1282,7 +1282,7 @@ xmlns:c16r2=\"http://schemas.microsoft.com/office/draw
 		{
 			writer.WriteString(L"<");
 			writer.WriteString(sNodeName);
-			if (NULL != m_l.IsInit())
+			if (0 != m_l.IsInit())
 			{
 				WritingStringAttrDouble(L"l", *m_l);
 			}
