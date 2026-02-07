--- sendmail/readcf.c.orig	2025-10-23 19:33:31 UTC
+++ sendmail/readcf.c
@@ -3213,6 +3213,10 @@ static struct optioninfo
 	{ "SameDomainOnly",		O_SAMEDOMAINONLY,	OI_NONE	},
 #endif
 
+#if USE_BLACKLIST
+# define O_BLACKLIST		0xfb
+	{ "UseBlacklist",	O_BLACKLIST,	OI_NONE	},
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
+#if USE_BLACKLIST
+	  case O_BLACKLIST:
+		UseBlacklist = atobool(val);
 		break;
 #endif
 
