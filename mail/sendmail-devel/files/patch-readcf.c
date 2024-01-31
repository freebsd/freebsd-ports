--- sendmail/readcf.c.orig	2024-01-25 05:27:02 UTC
+++ sendmail/readcf.c
@@ -3208,6 +3208,10 @@ static struct optioninfo
 	{ "CipherSuites",		O_CIPHERSUITES,	OI_NONE	},
 #endif
 
+#if USE_BLACKLIST
+# define O_BLACKLIST		0xfb
+	{ "UseBlacklist",	O_BLACKLIST,	OI_NONE	},
+#endif
 	{ NULL,				'\0',		OI_NONE	}
 };
 
@@ -4943,6 +4947,12 @@ setoption(opt, val, safe, sticky, e)
 #if _FFR_MTA_STS
 	  case O_MTASTS:
 		MTASTS = atobool(val);
+		break;
+#endif
+
+#if USE_BLACKLIST
+	  case O_BLACKLIST:
+		UseBlacklist = atobool(val);
 		break;
 #endif
 
