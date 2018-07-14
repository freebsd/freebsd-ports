--- rtrmgr/lex.boot.cc.orig	2018-07-12 14:00:49 UTC
+++ rtrmgr/lex.boot.cc
@@ -9674,9 +9674,9 @@ YY_MALLOC_DECL
 
 YY_DECL
 	{
-	register yy_state_type yy_current_state;
-	register char *yy_cp, *yy_bp;
-	register int yy_act;
+	yy_state_type yy_current_state;
+	char *yy_cp, *yy_bp;
+	int yy_act;
 
 #line 242 "boot.ll"
 
@@ -9723,7 +9723,7 @@ YY_DECL
 yy_match:
 		do
 			{
-			register YY_CHAR yy_c = yy_ec[YY_SC_TO_UI(*yy_cp)];
+			YY_CHAR yy_c = yy_ec[YY_SC_TO_UI(*yy_cp)];
 			if ( yy_accept[yy_current_state] )
 				{
 				yy_last_accepting_state = yy_current_state;
@@ -10246,9 +10246,9 @@ case YY_STATE_EOF(arith):
 
 static int yy_get_next_buffer()
 	{
-	register char *dest = yy_current_buffer->yy_ch_buf;
-	register char *source = yytext_ptr;
-	register int number_to_move, i;
+	char *dest = yy_current_buffer->yy_ch_buf;
+	char *source = yytext_ptr;
+	int number_to_move, i;
 	int ret_val;
 
 	if ( yy_c_buf_p > &yy_current_buffer->yy_ch_buf[yy_n_chars + 1] )
@@ -10378,14 +10378,14 @@ static int yy_get_next_buffer()
 
 static yy_state_type yy_get_previous_state()
 	{
-	register yy_state_type yy_current_state;
-	register char *yy_cp;
+	yy_state_type yy_current_state;
+	char *yy_cp;
 
 	yy_current_state = yy_start;
 
 	for ( yy_cp = yytext_ptr + YY_MORE_ADJ; yy_cp < yy_c_buf_p; ++yy_cp )
 		{
-		register YY_CHAR yy_c = (*yy_cp ? yy_ec[YY_SC_TO_UI(*yy_cp)] : 1);
+		YY_CHAR yy_c = (*yy_cp ? yy_ec[YY_SC_TO_UI(*yy_cp)] : 1);
 		if ( yy_accept[yy_current_state] )
 			{
 			yy_last_accepting_state = yy_current_state;
@@ -10417,10 +10417,10 @@ static yy_state_type yy_try_NUL_trans( y
 yy_state_type yy_current_state;
 #endif
 	{
-	register int yy_is_jam;
-	register char *yy_cp = yy_c_buf_p;
+	int yy_is_jam;
+	char *yy_cp = yy_c_buf_p;
 
-	register YY_CHAR yy_c = 1;
+	YY_CHAR yy_c = 1;
 	if ( yy_accept[yy_current_state] )
 		{
 		yy_last_accepting_state = yy_current_state;
@@ -10441,14 +10441,14 @@ yy_state_type yy_current_state;
 
 #ifndef YY_NO_UNPUT
 #ifdef YY_USE_PROTOS
-static void yyunput( int c, register char *yy_bp )
+static void yyunput( int c, char *yy_bp )
 #else
 static void yyunput( c, yy_bp )
 int c;
-register char *yy_bp;
+char *yy_bp;
 #endif
 	{
-	register char *yy_cp = yy_c_buf_p;
+	char *yy_cp = yy_c_buf_p;
 
 	/* undo effects of setting up yytext */
 	*yy_cp = yy_hold_char;
@@ -10456,10 +10456,10 @@ register char *yy_bp;
 	if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )
 		{ /* need to shift things up to make room */
 		/* +2 for EOB chars. */
-		register int number_to_move = yy_n_chars + 2;
-		register char *dest = &yy_current_buffer->yy_ch_buf[
+		int number_to_move = yy_n_chars + 2;
+		char *dest = &yy_current_buffer->yy_ch_buf[
 					yy_current_buffer->yy_buf_size + 2];
-		register char *source =
+		char *source =
 				&yy_current_buffer->yy_ch_buf[number_to_move];
 
 		while ( source > yy_current_buffer->yy_ch_buf )
@@ -10921,7 +10921,7 @@ yyconst char *s2;
 int n;
 #endif
 	{
-	register int i;
+	int i;
 	for ( i = 0; i < n; ++i )
 		s1[i] = s2[i];
 	}
@@ -10935,7 +10935,7 @@ static int yy_flex_strlen( s )
 yyconst char *s;
 #endif
 	{
-	register int n;
+	int n;
 	for ( n = 0; s[n]; ++n )
 		;
 
