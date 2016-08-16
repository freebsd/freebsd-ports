--- src/lang-bison.y.orig	2006-09-11 01:32:12 UTC
+++ src/lang-bison.y
@@ -15,7 +15,7 @@ int lang_lineno = 1;
 
 std::stack<PhraseBlock *> pbs;
 
-int yy_lang_error (char *s);
+int yy_lang_error (const char *s);
 int yy_lang_lex (void);
 %}
 
@@ -121,7 +121,7 @@ phrase:
 
 extern char *yy_lang_text;
 
-int yy_lang_error (char *s)
+int yy_lang_error (const char *s)
 {
 	fprintf (stderr, "lang-parse: %s in line %i, at symbol \"%s\"\n",
 			s, lang_lineno, yy_lang_text);
