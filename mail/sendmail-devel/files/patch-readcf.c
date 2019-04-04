--- sendmail/readcf.c.orig	2019-02-15 10:30:19 UTC
+++ sendmail/readcf.c
@@ -2988,6 +2988,10 @@ static struct optioninfo
 	{ "ClientCACertPath",			O_CLTCACERTPATH, OI_NONE },
 #endif
 
+#if USE_BLACKLIST
+# define O_BLACKLIST		0xf2
+	{ "UseBlacklist",	O_BLACKLIST,	OI_NONE	},
+#endif
 	{ NULL,				'\0',		OI_NONE	}
 };
 
@@ -4661,6 +4665,12 @@ setoption(opt, val, safe, sticky, e)
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
