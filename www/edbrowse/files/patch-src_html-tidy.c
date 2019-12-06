--- src/html-tidy.c.orig	2019-12-06 06:26:39 UTC
+++ src/html-tidy.c
@@ -126,7 +126,7 @@ void html2nodes(const char *htmltext, bool startpage)
 	tidyOptSetBool(tdoc, TidyDropEmptyElems, no);
 	tidyOptSetBool(tdoc, TidyDropEmptyParas, no);
 	tidyOptSetBool(tdoc, TidyLiteralAttribs, yes);
-	tidyOptSetBool(tdoc, TidyStyleTags, no);
+	//tidyOptSetBool(tdoc, TidyStyleTags, no);
 
 	tidySetCharEncoding(tdoc, (cons_utf8 ? "utf8" : "latin1"));
 
