--- src/protocols/oscar/oscar.c.orig	Sat Oct 11 00:10:06 2003
+++ src/protocols/oscar/oscar.c	Sat Oct 11 00:13:51 2003
@@ -5391,11 +5391,11 @@
 		}
 
 		if ((bi != NULL) && (bi->ipaddr)) {
-			char *tstr =  g_strdup_printf("%hhd.%hhd.%hhd.%hhd",
-							(bi->ipaddr & 0xff000000) >> 24,
-							(bi->ipaddr & 0x00ff0000) >> 16,
-							(bi->ipaddr & 0x0000ff00) >> 8,
-							(bi->ipaddr & 0x000000ff));
+			char *tstr =  g_strdup_printf("%hhu.%hhu.%hhu.%hhu",
+							(char)(bi->ipaddr >> 24),
+							(char)(bi->ipaddr >> 16),
+							(char)(bi->ipaddr >> 8),
+							(char)bi->ipaddr);
 			tmp = ret;
 			ret = g_strconcat(tmp, _("<b>IP Address:</b> "), tstr, "\n", NULL);
 			g_free(tmp);
