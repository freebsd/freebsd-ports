--- htmldoc/htmlsep.cxx.orig	2013-08-09 13:43:34 UTC
+++ htmldoc/htmlsep.cxx
@@ -524,7 +524,7 @@ write_doc(FILE   **out,			// I - Output 
     if (t->markup >= MARKUP_H1 && t->markup < (MARKUP_H1 + TocLevels) &&
         htmlGetVariable(t, (uchar *)"_HD_OMIT_TOC") == NULL)
     {
-      if (heading >= 0)
+      if (*heading >= 0)
         write_footer(out, *heading);
 
       (*heading) ++;
