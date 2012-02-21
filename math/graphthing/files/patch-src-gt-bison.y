--- src/gt-bison.y.orig	2012-02-21 14:11:30.000000000 +0100
+++ src/gt-bison.y	2012-02-21 14:11:53.000000000 +0100
@@ -18,7 +18,7 @@
 
 extern char *yy_gt_text;
 
-int yy_gt_error (char *s);
+int yy_gt_error (const char *s);
 int yy_gt_lex (void);
 %}
 
@@ -132,7 +132,7 @@
 
 %%
 
-int yy_gt_error (char *s)
+int yy_gt_error (const char *s)
 {
 	fprintf (stderr, "gt-parse: %s in line %i, at symbol \"%s\"\n",
 					s, gt_lineno, yy_gt_text);
