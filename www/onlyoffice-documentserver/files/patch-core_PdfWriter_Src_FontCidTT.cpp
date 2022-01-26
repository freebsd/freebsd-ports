--- core/PdfWriter/Src/FontCidTT.cpp.orig	2022-01-19 13:47:39 UTC
+++ core/PdfWriter/Src/FontCidTT.cpp
@@ -222,7 +222,7 @@ namespace PdfWriter
 	unsigned short CFontCidTrueType::EncodeChar(const unsigned int &unUnicode)
 	{
 		if (!OpenFontFace())
-			return NULL;
+			return 0;
 
 		std::map<unsigned int, unsigned short>::const_iterator oIter = m_mUnicodeToCode.find(unUnicode);
 		if (oIter != m_mUnicodeToCode.end())
