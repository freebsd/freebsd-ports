--- sendmail/readcf.c.orig	2026-06-19 08:47:02 UTC
+++ sendmail/readcf.c
@@ -3177,6 +3177,11 @@ static struct optioninfo
 	{ "TLSEC",			O_TLS_EC,	OI_NONE	},
 #endif
 
+#if USE_BLOCKLIST
+# define O_BLOCKLIST		0xfb
+	{ "UseBlocklist",	O_BLOCKLIST,	OI_NONE	},
+	{ "UseBlacklist",	O_BLOCKLIST,	OI_NONE	}, /* alias */
+#endif
 	{ NULL,				'\0',		OI_NONE	}
 };
 
@@ -4909,6 +4914,12 @@ setoption(int opt, char *val, bool safe, bool sticky, 
 #if _FFR_MTA_STS
 	  case O_MTASTS:
 		StrictTransportSecurity = atobool(val);
+		break;
+#endif
+
+#if USE_BLOCKLIST
+	  case O_BLOCKLIST:
+		UseBlocklist = atobool(val);
 		break;
 #endif
 
