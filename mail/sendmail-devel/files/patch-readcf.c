--- sendmail/readcf.c.orig	2026-03-09 16:19:10 UTC
+++ sendmail/readcf.c
@@ -3175,6 +3175,11 @@ static struct optioninfo
 	{ "SameDomainOnly",		O_SAMEDOMAINONLY,	OI_NONE	},
 #endif
 
+#if USE_BLOCKLIST
+# define O_BLOCKLIST		0xfb
+	{ "UseBlocklist",	O_BLOCKLIST,	OI_NONE	},
+	{ "UseBlacklist",	O_BLOCKLIST,	OI_NONE	}, /* alias */
+#endif
 	{ NULL,				'\0',		OI_NONE	}
 };
 
@@ -4901,6 +4906,12 @@ setoption(int opt, char *val, bool safe, bool sticky, 
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
 
