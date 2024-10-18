--- src/account/nntp.c.orig	2024-10-10 23:44:04 UTC
+++ src/account/nntp.c
@@ -41,7 +41,7 @@ static AccountConfig const _nntp_config[] =
 	{ "username",	"Username",		ACT_STRING,	NULL	},
 	{ "password",	"Password",		ACT_PASSWORD,	NULL	},
 	{ "hostname",	"Server hostname",	ACT_STRING,	NULL	},
-	{ "port",	"Server port",		ACT_UINT16,	119	},
+	{ "port",	"Server port",		ACT_UINT16,	(void *)119 },
 	{ "ssl",	"Use SSL",		ACT_BOOLEAN,	0	},
 	{ NULL,		NULL,			ACT_NONE,	NULL	}
 };
