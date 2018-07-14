--- policy/lex.yy_policy_parser.cc.orig	2018-07-12 13:40:14 UTC
+++ policy/lex.yy_policy_parser.cc
@@ -3092,9 +3092,9 @@ extern int yy_policy_parserlex (void);
  */
 YY_DECL
 {
-	register yy_state_type yy_current_state;
-	register char *yy_cp, *yy_bp;
-	register int yy_act;
+	yy_state_type yy_current_state;
+	char *yy_cp, *yy_bp;
+	int yy_act;
     
 #line 62 "policy.l"
 
@@ -3143,7 +3143,7 @@ YY_DECL
 yy_match:
 		do
 			{
-			register YY_CHAR yy_c = yy_ec[YY_SC_TO_UI(*yy_cp)];
+			YY_CHAR yy_c = yy_ec[YY_SC_TO_UI(*yy_cp)];
 			if ( yy_accept[yy_current_state] )
 				{
 				(yy_last_accepting_state) = yy_current_state;
@@ -3667,9 +3667,9 @@ case YY_STATE_EOF(STR):
  */
 static int yy_get_next_buffer (void)
 {
-    	register char *dest = YY_CURRENT_BUFFER_LVALUE->yy_ch_buf;
-	register char *source = (yytext_ptr);
-	register int number_to_move, i;
+    	char *dest = YY_CURRENT_BUFFER_LVALUE->yy_ch_buf;
+	char *source = (yytext_ptr);
+	int number_to_move, i;
 	int ret_val;
 
 	if ( (yy_c_buf_p) > &YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[(yy_n_chars) + 1] )
@@ -3793,14 +3793,14 @@ static int yy_get_next_buffer (void)
 
     static yy_state_type yy_get_previous_state (void)
 {
-	register yy_state_type yy_current_state;
-	register char *yy_cp;
+	yy_state_type yy_current_state;
+	char *yy_cp;
     
 	yy_current_state = (yy_start);
 
 	for ( yy_cp = (yytext_ptr) + YY_MORE_ADJ; yy_cp < (yy_c_buf_p); ++yy_cp )
 		{
-		register YY_CHAR yy_c = (*yy_cp ? yy_ec[YY_SC_TO_UI(*yy_cp)] : 1);
+		YY_CHAR yy_c = (*yy_cp ? yy_ec[YY_SC_TO_UI(*yy_cp)] : 1);
 		if ( yy_accept[yy_current_state] )
 			{
 			(yy_last_accepting_state) = yy_current_state;
@@ -3825,10 +3825,10 @@ static int yy_get_next_buffer (void)
  */
     static yy_state_type yy_try_NUL_trans  (yy_state_type yy_current_state )
 {
-	register int yy_is_jam;
-    	register char *yy_cp = (yy_c_buf_p);
+	int yy_is_jam;
+    	char *yy_cp = (yy_c_buf_p);
 
-	register YY_CHAR yy_c = 1;
+	YY_CHAR yy_c = 1;
 	if ( yy_accept[yy_current_state] )
 		{
 		(yy_last_accepting_state) = yy_current_state;
@@ -4429,7 +4429,7 @@ int yy_policy_parserlex_destroy  (void)
 #ifndef yytext_ptr
 static void yy_flex_strncpy (char* s1, yyconst char * s2, int n )
 {
-	register int i;
+	int i;
 	for ( i = 0; i < n; ++i )
 		s1[i] = s2[i];
 }
@@ -4438,7 +4438,7 @@ static void yy_flex_strncpy (char* s1, y
 #ifdef YY_NEED_STRLEN
 static int yy_flex_strlen (yyconst char * s )
 {
-	register int n;
+	int n;
 	for ( n = 0; s[n]; ++n )
 		;
 
