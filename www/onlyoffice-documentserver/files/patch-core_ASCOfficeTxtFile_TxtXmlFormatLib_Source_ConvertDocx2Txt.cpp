--- core/ASCOfficeTxtFile/TxtXmlFormatLib/Source/ConvertDocx2Txt.cpp.orig	2022-01-19 14:08:20 UTC
+++ core/ASCOfficeTxtFile/TxtXmlFormatLib/Source/ConvertDocx2Txt.cpp
@@ -159,7 +159,7 @@ namespace Docx2Txt
 	const std::wstring Converter_Impl::m_letters = _T("abcdefghijklmnopqrstuvwxyz");
 
 	Converter_Impl::Converter_Impl()
-		:  Lists(NULL), NoteCount(0), listNumPrev(1)
+		:  Lists(0), NoteCount(0), listNumPrev(1)
 	{
 	}
 
