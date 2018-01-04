--- sendmail/readcf.c.orig	2015-06-17 16:51:58 UTC
+++ sendmail/readcf.c
@@ -2910,6 +2910,10 @@ static struct optioninfo
 #endif
 #define O_USECOMPRESSEDIPV6ADDRESSES 0xec
 	{ "UseCompressedIPv6Addresses",	O_USECOMPRESSEDIPV6ADDRESSES, OI_NONE },
+#if USE_BLACKLIST
+# define O_BLACKLIST		0xf2
+	{ "UseBlacklist",	O_BLACKLIST,	OI_NONE	},
+#endif
 
 	{ NULL,				'\0',		OI_NONE	}
 };
@@ -4540,6 +4544,12 @@ setoption(opt, val, safe, sticky, e)
 		UseCompressedIPv6Addresses = atobool(val);
 		break;
 
+#if USE_BLACKLIST
+	  case O_BLACKLIST:
+		UseBlacklist = atobool(val);
+		break;
+#endif
+
 	  default:
 		if (tTd(37, 1))
 		{
