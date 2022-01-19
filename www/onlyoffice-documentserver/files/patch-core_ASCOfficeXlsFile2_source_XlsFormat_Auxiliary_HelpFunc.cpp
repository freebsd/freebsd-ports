--- core/ASCOfficeXlsFile2/source/XlsFormat/Auxiliary/HelpFunc.cpp.orig	2021-09-30 12:13:32 UTC
+++ core/ASCOfficeXlsFile2/source/XlsFormat/Auxiliary/HelpFunc.cpp
@@ -359,7 +359,7 @@ const std::wstring unescape_ST_Xstring(const std::wstr
     while(true)
 	{
         
-#if defined(__linux__) || defined(_MAC) || defined(_IOS)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(_MAC) || defined(_IOS)
 		const auto it_range = boost::make_iterator_range(x_pos_noncopied, wstr_end);
         x_pos_next = boost::algorithm::find_first(it_range, L"_x").begin();
 #else
