-- Fix build with utf8cpp >= 4.2.0: validate_next(it, end, cp) was changed to
-- validate_next(it, end) removing the code_point parameter. Use utf8::next()
-- instead, which returns the code point and throws on invalid UTF-8.
--- src/parse/pdf_resources/page_font.h.orig	2026-10-31 02:07:34 UTC
+++ src/parse/pdf_resources/page_font.h
@@ -2796,8 +2796,12 @@ namespace pdflib
       // Only a mapping to a single unusable code point is discarded.
       auto itr = value.begin();
       utf8::utfchar32_t cp = 0;
-      if(utf8::internal::validate_next(itr, value.end(), cp)!=utf8::internal::UTF8_OK
-	 or itr!=value.end())
+      try {
+	cp = utf8::next(itr, value.end());
+      } catch (const utf8::exception&) {
+	return true;
+      }
+      if(itr!=value.end())
 	{
 	  return true;
 	}
