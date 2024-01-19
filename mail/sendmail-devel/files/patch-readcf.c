--- sendmail/readcf.c.orig	2023-12-19 05:29:19 UTC
+++ sendmail/readcf.c
@@ -3208,6 +3208,10 @@ static struct optioninfo
 	{ "CipherSuites",		O_CIPHERSUITES,	OI_NONE	},
 #endif
 
+#if USE_BLACKLIST
+# define O_BLACKLIST		0xf2
+	{ "UseBlacklist",	O_BLACKLIST,	OI_NONE	},
+#endif
 	{ NULL,				'\0',		OI_NONE	}
 };
 
@@ -4946,6 +4950,12 @@ setoption(opt, val, safe, sticky, e)
 		break;
 #endif
 
+#if USE_BLACKLIST
+	  case O_BLACKLIST:
+		UseBlacklist = atobool(val);
+		break;
+#endif
+
 	  default:
 		if (tTd(37, 1))
 		{
