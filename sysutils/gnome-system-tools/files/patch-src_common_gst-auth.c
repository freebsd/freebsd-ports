--- src/common/gst-auth.c.orig	Sun Aug  1 20:04:13 2004
+++ src/common/gst-auth.c	Mon Aug 23 13:00:40 2004
@@ -300,14 +300,16 @@
 	lc_all      = getenv ("LC_ALL");
 	lang        = getenv ("LANG");
 
+	g_string_append (command, "env ");
+
 	if (lc_all)
-		g_string_append_printf (command, "export LC_ALL=\"%s\" && ", lc_all);
-	else if (lc_messages)
-		g_string_append_printf (command, "export LC_MESSAGES=\"%s\" && ", lc_messages);
-	else if (lang)
-		g_string_append_printf (command, "export LANG=\"%s\" && ", lang);
-	else if (language)
-		g_string_append_printf (command, "export LANGUAGE=\"%s\" && ", language);
+		g_string_append_printf (command, "LC_ALL=\"%s\" ", lc_all);
+	if (lc_messages)
+		g_string_append_printf (command, "LC_MESSAGES=\"%s\" ", lc_messages);
+	if (lang)
+		g_string_append_printf (command, "LANG=\"%s\" ", lang);
+	if (language)
+		g_string_append_printf (command, "LANGUAGE=\"%s\" ", language);
 }
 
 void
