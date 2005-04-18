--- lex.c.orig	Thu Apr 14 16:07:26 2005
+++ lex.c	Thu Apr 14 14:48:11 2005
@@ -153,8 +153,6 @@
 		} \
 	while ( 0 )
 
-#define unput(c) yyunput( c, yytext_ptr )
-
 /* The following is because we cannot portably get our hands on size_t
  * (without autoconf's help, which isn't available because we want
  * flex-generated scanners to compile on their own).
@@ -657,10 +655,6 @@
 #endif
 #endif
 
-#ifndef YY_NO_UNPUT
-static void yyunput YY_PROTO(( int c, char *buf_ptr ));
-#endif
-
 #ifndef yytext_ptr
 static void yy_flex_strncpy YY_PROTO(( char *, yyconst char *, int ));
 #endif
@@ -1662,51 +1656,6 @@
 
 	return yy_is_jam ? 0 : yy_current_state;
 	}
-
-
-#ifndef YY_NO_UNPUT
-#ifdef YY_USE_PROTOS
-static void yyunput( int c, register char *yy_bp )
-#else
-static void yyunput( c, yy_bp )
-int c;
-register char *yy_bp;
-#endif
-	{
-	register char *yy_cp = yy_c_buf_p;
-
-	/* undo effects of setting up yytext */
-	*yy_cp = yy_hold_char;
-
-	if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )
-		{ /* need to shift things up to make room */
-		/* +2 for EOB chars. */
-		register int number_to_move = yy_n_chars + 2;
-		register char *dest = &yy_current_buffer->yy_ch_buf[
-					yy_current_buffer->yy_buf_size + 2];
-		register char *source =
-				&yy_current_buffer->yy_ch_buf[number_to_move];
-
-		while ( source > yy_current_buffer->yy_ch_buf )
-			*--dest = *--source;
-
-		yy_cp += (int) (dest - source);
-		yy_bp += (int) (dest - source);
-		yy_current_buffer->yy_n_chars =
-			yy_n_chars = yy_current_buffer->yy_buf_size;
-
-		if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )
-			YY_FATAL_ERROR( "flex scanner push-back overflow" );
-		}
-
-	*--yy_cp = (char) c;
-
-
-	yytext_ptr = yy_bp;
-	yy_hold_char = *yy_cp;
-	yy_c_buf_p = yy_cp;
-	}
-#endif	/* ifndef YY_NO_UNPUT */
 
 
 #ifdef __cplusplus
