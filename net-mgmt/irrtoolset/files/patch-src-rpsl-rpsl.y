--- src/rpsl/rpsl.y.orig	2012-07-31 12:10:39 UTC
+++ src/rpsl/rpsl.y
@@ -75,7 +75,7 @@ extern void handle_object_error(const ch
 extern void handle_warning(const char *, ...);
 extern int yylex();
 char *token_name(int token_id);
-void rpslerror(const char *s, ...);
+void rpslerror(void *, const char *s, ...);
 Attr *changeCurrentAttr(Attr *b);
 void handleArgumentTypeError(char *attr, const char *method, int position,
 			     const RPType *correctType, 
@@ -83,7 +83,6 @@ void handleArgumentTypeError(char *attr,
 const AttrMethod *searchMethod(const AttrRPAttr *rp_attr, const char *method, ItemList *args);
 
 /* argument to yyparse result of parsing should be stored here */
-#define YYPARSE_PARAM object	
 #define yyschema schema
 #define enable_yy_parser_debugging enable_rpsl_parser_debugging
 
@@ -91,8 +90,9 @@ extern Object *current_object;
 
 %}
 
-%name-prefix="rpsl"
-%output="rpsl.y.cc"
+%name-prefix "rpsl"
+%output "rpsl.y.cc"
+%parse-param {void *object}
 
 %expect 1
 
