
$FreeBSD$

--- cfg.y.orig
+++ cfg.y
@@ -210,6 +210,7 @@
 %token UNIX_SOCK_CHILDREN
 %token UNIX_TX_TIMEOUT
 %token SERVER_SIGNATURE
+%token SERVER_NAME
 %token REPLY_TO_VIA
 %token LOADMODULE
 %token MODPARAM
@@ -610,6 +611,7 @@
 		| TLS_SEND_TIMEOUT EQUAL error { yyerror("number expected"); }
 		| SERVER_SIGNATURE EQUAL NUMBER { server_signature=$3; }
 		| SERVER_SIGNATURE EQUAL error { yyerror("boolean value expected"); }
+		| SERVER_NAME EQUAL STRING { server_name=$3; }
 		| REPLY_TO_VIA EQUAL NUMBER { reply_to_via=$3; }
 		| REPLY_TO_VIA EQUAL error { yyerror("boolean value expected"); }
 		| LISTEN EQUAL id_lst {
