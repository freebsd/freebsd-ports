--- xlhtml/html.c.orig	2002-04-11 04:01:05 UTC
+++ xlhtml/html.c
@@ -47,8 +47,8 @@ extern void output_cell( cell *, int); 
 extern uni_string author;
 extern int null_string(U8 *);
 extern unsigned int next_font; 
-work_sheet **ws_array;
-font_attr **font_array;
+extern work_sheet **ws_array;
+extern font_attr **font_array;
 
 void output_header(void);
 void output_footer(void);
