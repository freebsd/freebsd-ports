--- sendmail/readcf.c.orig	2021-07-14 05:34:51 UTC
+++ sendmail/readcf.c
@@ -3056,6 +3056,10 @@ static struct optioninfo
 	{ "CipherSuites",		O_CIPHERSUITES,	OI_NONE	},
 #endif
 
+#if USE_BLACKLIST
+# define O_BLACKLIST		0xf2
+	{ "UseBlacklist",	O_BLACKLIST,	OI_NONE	},
+#endif
 	{ NULL,				'\0',		OI_NONE	}
 };
 
@@ -4795,6 +4799,12 @@ setoption(opt, val, safe, sticky, e)
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
