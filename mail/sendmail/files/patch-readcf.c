--- sendmail/readcf.c.orig	2020-06-02 09:41:43 UTC
+++ sendmail/readcf.c
@@ -2979,6 +2979,10 @@ static struct optioninfo
 	{ "SetCertAltnames",			O_CHECKALTNAMES, OI_NONE },
 #endif
 
+#if USE_BLACKLIST
+# define O_BLACKLIST		0xf2
+	{ "UseBlacklist",	O_BLACKLIST,	OI_NONE	},
+#endif
 	{ NULL,				'\0',		OI_NONE	}
 };
 
@@ -4678,6 +4682,12 @@ setoption(opt, val, safe, sticky, e)
 		SetCertAltnames = atobool(val);
 		break;
 # endif
+
+#if USE_BLACKLIST
+	  case O_BLACKLIST:
+		UseBlacklist = atobool(val);
+		break;
+#endif
 
 	  default:
 		if (tTd(37, 1))
