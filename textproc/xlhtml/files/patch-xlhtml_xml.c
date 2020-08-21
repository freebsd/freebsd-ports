--- xlhtml/xml.c.orig	2002-04-11 03:25:17 UTC
+++ xlhtml/xml.c
@@ -33,7 +33,7 @@ extern void update_default_alignment(unsigned int, int
 extern void output_cell( cell *, int); 
 extern uni_string author;
 
-work_sheet **ws_array;
+extern work_sheet **ws_array;
 
 
 void OutputTableXML(void)
