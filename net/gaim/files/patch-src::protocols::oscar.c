--- src/protocols/oscar/oscar.c.orig	Thu Oct  2 15:40:55 2003
+++ src/protocols/oscar/oscar.c	Thu Oct  2 15:59:38 2003
@@ -5462,11 +5462,11 @@
 			free(tstr);
 
 			if (bi->ipaddr) {
-				char *tstr =  g_strdup_printf("%hhd.%hhd.%hhd.%hhd",
-								(bi->ipaddr & 0xff000000) >> 24,
-								(bi->ipaddr & 0x00ff0000) >> 16,
-								(bi->ipaddr & 0x0000ff00) >> 8,
-								(bi->ipaddr & 0x000000ff));
+				char *tstr =  g_strdup_printf("%hhu.%hhu.%hhu.%hhu",
+								(char)(bi->ipaddr >> 24),
+								(char)(bi->ipaddr >> 16),
+								(char)(bi->ipaddr >> 8),
+								(char)bi->ipaddr);
 				tmp = yay;
 				yay = g_strconcat(tmp, _("<b>IP Address:</b> "), tstr, "\n", NULL);
 				free(tmp);
