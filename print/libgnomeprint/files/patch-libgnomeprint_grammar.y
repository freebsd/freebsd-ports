--- libgnomeprint/grammar.y.orig	2010-02-09 12:32:51 UTC
+++ libgnomeprint/grammar.y
@@ -6,8 +6,6 @@
 #include <libgnomeprint/types.h>
 #include <libgnomeprint/gnome-print-filter.h>
 
-#define YYPARSE_PARAM graph
-
 static void
 set_value_from_string (GParamSpec *pspec, GValue *v, const gchar *s)
 {
@@ -99,7 +97,7 @@ gnome_print_filter_parse_prop (GnomePrin
 }
 
 static int yylex (void *lvalp);
-static int yyerror (const char *s);
+static int yyerror (graph_t *g, const char *s);
 %}
 
 %union {
@@ -117,6 +115,7 @@ static int yyerror (const char *s);
 %type <p> pool
 
 %pure_parser
+%parse-param { graph_t *graph }
 
 %start graph
 %%
@@ -185,7 +184,7 @@ graph: filter {
 %%
 
 static int
-yyerror (const char *s)
+yyerror (graph_t *g, const char *s)
 {
 	return -1;
 }
