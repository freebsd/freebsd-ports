--- core/TxtFile/Source/ConvertDocx2Txt.cpp.orig	2023-02-13 11:13:27 UTC
+++ core/TxtFile/Source/ConvertDocx2Txt.cpp
@@ -149,7 +149,7 @@ namespace Docx2Txt
 	const std::wstring Converter_Impl::m_letters = _T("abcdefghijklmnopqrstuvwxyz");
 
 	Converter_Impl::Converter_Impl()
-		:  Lists(NULL), NoteCount(0), listNumPrev(1)
+		:  Lists(0), NoteCount(0), listNumPrev(1)
 	{
 	}
 
