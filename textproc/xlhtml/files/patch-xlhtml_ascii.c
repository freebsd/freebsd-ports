--- xlhtml/ascii.c.orig	2002-04-11 03:25:17 UTC
+++ xlhtml/ascii.c
@@ -48,9 +48,9 @@ extern void output_cell( cell *, int); 
 extern uni_string author;
 extern int null_string(U8 *);
 extern int Csv;
-work_sheet **ws_array;
-font_attr **font_array;
-xf_attr **xf_array;
+extern work_sheet **ws_array;
+extern font_attr **font_array;
+extern xf_attr **xf_array;
 
 extern int IsCellNumeric(cell *);
 extern int IsCellSafe(cell *);
