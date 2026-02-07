--- src/account/pop3.c.orig	2024-10-10 23:43:19 UTC
+++ src/account/pop3.c
@@ -154,7 +154,7 @@ static AccountConfig _pop3_config[P3CV_COUNT + 1] =
 	{ "username",	"Username",		ACT_STRING,	NULL },
 	{ "password",	"Password",		ACT_PASSWORD,	NULL },
 	{ "hostname",	"Server hostname",	ACT_STRING,	NULL },
-	{ "port",	"Server port",		ACT_UINT16,	110 },
+	{ "port",	"Server port",		ACT_UINT16,	(void *)110 },
 	{ "ssl",	"Use SSL",		ACT_BOOLEAN,	NULL },
 	{ "delete",	"Delete read mails on server",
 						ACT_BOOLEAN,	NULL },
