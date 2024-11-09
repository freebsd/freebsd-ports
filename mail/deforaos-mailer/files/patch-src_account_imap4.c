--- src/account/imap4.c.orig	2024-10-10 23:42:56 UTC
+++ src/account/imap4.c
@@ -190,7 +190,7 @@ AccountConfig const _imap4_config[I4CV_COUNT + 1] =
 	{ "username",	"Username",		ACT_STRING,	NULL	},
 	{ "password",	"Password",		ACT_PASSWORD,	NULL	},
 	{ "hostname",	"Server hostname",	ACT_STRING,	NULL	},
-	{ "port",	"Server port",		ACT_UINT16,	143	},
+	{ "port",	"Server port",		ACT_UINT16,	(void *)143 },
 	{ "ssl",	"Use SSL",		ACT_BOOLEAN,	0	},
 #if 0 /* XXX not implemented yet */
 	{ "sent",	"Sent mails folder",	ACT_NONE,	NULL	},
