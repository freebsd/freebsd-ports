--- grammar/lexer.l.ori	2012-12-31 21:57:37.000000000 -0700
+++ grammar/lexer.l	2012-12-31 21:57:51.000000000 -0700
@@ -88,7 +88,7 @@
 /* somehow, I need these prototype even though the headers are 
  * included. I guess that's some autotools magic I don't understand...
  */
-int fileno(FILE *stream);
+//int fileno(FILE *stream);
 
 %}
 
