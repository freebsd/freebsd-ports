
$FreeBSD$

--- cfg.lex	2004/06/29 19:08:42	1.1
+++ cfg.lex	2004/06/29 19:10:36
@@ -165,6 +165,7 @@
 FIFO fifo
 FIFO_MODE fifo_mode
 SERVER_SIGNATURE server_signature
+SERVER_NAME server_name
 REPLY_TO_VIA reply_to_via
 USER		"user"|"uid"
 GROUP		"group"|"gid"
@@ -332,6 +333,7 @@
 <INITIAL>{FIFO}	{ count(); yylval.strval=yytext; return FIFO; }
 <INITIAL>{FIFO_MODE}	{ count(); yylval.strval=yytext; return FIFO_MODE; }
 <INITIAL>{SERVER_SIGNATURE}	{ count(); yylval.strval=yytext; return SERVER_SIGNATURE; }
+<INITIAL>{SERVER_NAME}	{ count(); yylval.strval=yytext; return SERVER_NAME; }
 <INITIAL>{REPLY_TO_VIA}	{ count(); yylval.strval=yytext; return REPLY_TO_VIA; }
 <INITIAL>{ADVERTISED_ADDRESS}	{	count(); yylval.strval=yytext;
 									return ADVERTISED_ADDRESS; }
