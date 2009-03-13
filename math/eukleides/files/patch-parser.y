--- parser.y.orig	2009-03-13 18:38:32.000000000 +0100
+++ parser.y	2009-03-13 18:38:19.000000000 +0100
@@ -29,7 +29,6 @@
 int warning(char *);
 int yyerror(char *);
 
-int drawing_style = FULL;
 symrec* tracevar;
 double tracestep, tracebegin;
 int tracestyle, traceind = -1;
@@ -93,6 +92,10 @@
 %type <flag> drawing_flag segment_marking_flag angle_marking_flag color_flag
 %type <string> ident
 
+%{
+int drawing_style = FULL;
+%}
+
 %% 
 
 input:
