--- src/llsphinxql.c.orig	2018-02-03 15:30:11 UTC
+++ src/llsphinxql.c
@@ -1142,9 +1142,9 @@ extern int yylex (yyscan_t yyscanner);
  */
 YY_DECL
 {
-	register yy_state_type yy_current_state;
-	register char *yy_cp, *yy_bp;
-	register int yy_act;
+	yy_state_type yy_current_state;
+	char *yy_cp, *yy_bp;
+	int yy_act;
     struct yyguts_t * yyg = (struct yyguts_t*)yyscanner;
 
 #line 31 "sphinxql.l"
@@ -1194,7 +1194,7 @@ YY_DECL
 yy_match:
 		do
 			{
-			register YY_CHAR yy_c = yy_ec[YY_SC_TO_UI(*yy_cp)];
+			YY_CHAR yy_c = yy_ec[YY_SC_TO_UI(*yy_cp)];
 			if ( yy_accept[yy_current_state] )
 				{
 				yyg->yy_last_accepting_state = yy_current_state;
@@ -2080,9 +2080,9 @@ case YY_STATE_EOF(ccomment):
 static int yy_get_next_buffer (yyscan_t yyscanner)
 {
     struct yyguts_t * yyg = (struct yyguts_t*)yyscanner;
-	register char *dest = YY_CURRENT_BUFFER_LVALUE->yy_ch_buf;
-	register char *source = yyg->yytext_ptr;
-	register int number_to_move, i;
+	char *dest = YY_CURRENT_BUFFER_LVALUE->yy_ch_buf;
+	char *source = yyg->yytext_ptr;
+	int number_to_move, i;
 	int ret_val;
 
 	if ( yyg->yy_c_buf_p > &YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[yyg->yy_n_chars + 1] )
@@ -2214,15 +2214,15 @@ static int yy_get_next_buffer (yyscan_t yyscanner)
 
     static yy_state_type yy_get_previous_state (yyscan_t yyscanner)
 {
-	register yy_state_type yy_current_state;
-	register char *yy_cp;
+	yy_state_type yy_current_state;
+	char *yy_cp;
     struct yyguts_t * yyg = (struct yyguts_t*)yyscanner;
 
 	yy_current_state = yyg->yy_start;
 
 	for ( yy_cp = yyg->yytext_ptr + YY_MORE_ADJ; yy_cp < yyg->yy_c_buf_p; ++yy_cp )
 		{
-		register YY_CHAR yy_c = (*yy_cp ? yy_ec[YY_SC_TO_UI(*yy_cp)] : 1);
+		YY_CHAR yy_c = (*yy_cp ? yy_ec[YY_SC_TO_UI(*yy_cp)] : 1);
 		if ( yy_accept[yy_current_state] )
 			{
 			yyg->yy_last_accepting_state = yy_current_state;
@@ -2247,11 +2247,11 @@ static int yy_get_next_buffer (yyscan_t yyscanner)
  */
     static yy_state_type yy_try_NUL_trans  (yy_state_type yy_current_state , yyscan_t yyscanner)
 {
-	register int yy_is_jam;
+	int yy_is_jam;
     struct yyguts_t * yyg = (struct yyguts_t*)yyscanner; /* This var may be unused depending upon options. */
-	register char *yy_cp = yyg->yy_c_buf_p;
+	char *yy_cp = yyg->yy_c_buf_p;
 
-	register YY_CHAR yy_c = 1;
+	YY_CHAR yy_c = 1;
 	if ( yy_accept[yy_current_state] )
 		{
 		yyg->yy_last_accepting_state = yy_current_state;
@@ -3013,7 +3013,7 @@ int yylex_destroy  (yyscan_t yyscanner)
 #ifndef yytext_ptr
 static void yy_flex_strncpy (char* s1, yyconst char * s2, int n , yyscan_t yyscanner)
 {
-	register int i;
+	int i;
 	for ( i = 0; i < n; ++i )
 		s1[i] = s2[i];
 }
@@ -3022,7 +3022,7 @@ static void yy_flex_strncpy (char* s1, yyconst char * 
 #ifdef YY_NEED_STRLEN
 static int yy_flex_strlen (yyconst char * s , yyscan_t yyscanner)
 {
-	register int n;
+	int n;
 	for ( n = 0; s[n]; ++n )
 		;
 
