--- src/gt-bison.y.orig	2006-09-11 01:32:12 UTC
+++ src/gt-bison.y
@@ -18,7 +18,7 @@ Edge *e;
 
 extern char *yy_gt_text;
 
-int yy_gt_error (char *s);
+int yy_gt_error (const char *s);
 int yy_gt_lex (void);
 %}
 
@@ -132,7 +132,7 @@ edge_property:
 
 %%
 
-int yy_gt_error (char *s)
+int yy_gt_error (const char *s)
 {
 	fprintf (stderr, "gt-parse: %s in line %i, at symbol \"%s\"\n",
 					s, gt_lineno, yy_gt_text);
