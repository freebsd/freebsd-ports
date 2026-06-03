--- src/libkstmath/escan.cpp.orig	2022-02-16 19:03:30 UTC
+++ src/libkstmath/escan.cpp
@@ -1317,9 +1317,9 @@ static int yy_get_next_buffer (void)
 	return yy_is_jam ? 0 : yy_current_state;
 }
 #if 0
-    static void yyunput (int c, register char * yy_bp )
+    static void yyunput (int c, char * yy_bp )
 {
-	register char *yy_cp;
+	char *yy_cp;
     
     yy_cp = (yy_c_buf_p);
 
@@ -1329,10 +1329,10 @@ static int yy_get_next_buffer (void)
 	if ( yy_cp < YY_CURRENT_BUFFER_LVALUE->yy_ch_buf + 2 )
 		{ /* need to shift things up to make room */
 		/* +2 for EOB chars. */
-		register int number_to_move = (yy_n_chars) + 2;
-		register char *dest = &YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[
+		int number_to_move = (yy_n_chars) + 2;
+		char *dest = &YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[
 					YY_CURRENT_BUFFER_LVALUE->yy_buf_size + 2];
-		register char *source =
+		char *source =
 				&YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[number_to_move];
 
 		while ( source > YY_CURRENT_BUFFER_LVALUE->yy_ch_buf )
@@ -1953,7 +1953,7 @@ int yylex_destroy  (void)
 #ifndef yytext_ptr
 static void yy_flex_strncpy (char* s1, yyconst char * s2, int n )
 {
-	register int i;
+	int i;
 	for ( i = 0; i < n; ++i )
 		s1[i] = s2[i];
 }
@@ -1962,7 +1962,7 @@ static void yy_flex_strncpy (char* s1, yyconst char * 
 #ifdef YY_NEED_STRLEN
 static int yy_flex_strlen (yyconst char * s )
 {
-	register int n;
+	int n;
 	for ( n = 0; s[n]; ++n )
 		;
 
