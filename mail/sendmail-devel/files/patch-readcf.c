--- sendmail/readcf.c.orig	2025-04-09 08:39:43 UTC
+++ sendmail/readcf.c
@@ -3206,6 +3206,10 @@ static struct optioninfo
 	{ "CipherSuites",		O_CIPHERSUITES,	OI_NONE	},
 #endif
 
+#if USE_BLACKLIST
+# define O_BLACKLIST		0xfb
+	{ "UseBlacklist",	O_BLACKLIST,	OI_NONE	},
+#endif
 	{ NULL,				'\0',		OI_NONE	}
 };
 
@@ -4941,6 +4945,12 @@ setoption(opt, val, safe, sticky, e)
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
 
