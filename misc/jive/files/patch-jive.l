--- jive.l.orig	1997-02-03 11:04:51.000000000 +0000
+++ jive.l
@@ -8,7 +8,7 @@ BW [ 	]
 EW [ 	.,;!?]
 
 %{
-#define YY_DECL char * yylex YY_PROTO(( void ))
+#define YY_DECL char * yylex ( void )
 	char buf[128];
 %}
 
