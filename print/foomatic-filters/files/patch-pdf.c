--- pdf.c.orig	2012-07-02 14:50:46 UTC
+++ pdf.c
@@ -46,9 +46,8 @@ static int pdf_count_pages(const char *filename)
     int pagecount;
 
     snprintf(gscommand, 4095, "%s -dNODISPLAY -q -c "
-	     "'/pdffile (%s) (r) file def pdfdict begin pdffile pdfopen begin "
-	     "(PageCount: ) print pdfpagecount == flush currentdict pdfclose "
-	     "end end quit'",
+	     "'/pdffile (%s) (r) file runpdfbegin (PageCount: ) print "
+	     "pdfpagecount = quit'",
 	     gspath, filename);
 
     FILE *pd = popen(gscommand, "r");
