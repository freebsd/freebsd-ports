--- sendmail/readcf.c.orig	2025-10-23 19:33:31 UTC
+++ sendmail/readcf.c
@@ -3213,6 +3213,11 @@ static struct optioninfo
 	{ "SameDomainOnly",		O_SAMEDOMAINONLY,	OI_NONE	},
 #endif
 
+#if USE_BLOCKLIST
+# define O_BLOCKLIST		0xfb
+	{ "UseBlocklist",	O_BLOCKLIST,	OI_NONE	},
+	{ "UseBlacklist",	O_BLOCKLIST,	OI_NONE	}, /* alias */
+#endif
 	{ NULL,				'\0',		OI_NONE	}
 };
 
@@ -4944,6 +4948,12 @@ setoption(opt, val, safe, sticky, e)
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
 
