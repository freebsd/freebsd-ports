--- src/common/gst-auth.c.orig	Sat Aug 21 01:01:33 2004
+++ src/common/gst-auth.c	Sat Aug 21 01:06:24 2004
@@ -300,6 +300,7 @@
 	lc_all      = getenv ("LC_ALL");
 	lang        = getenv ("LANG");
 
+#ifndef __FreeBSD__
 	if (lc_all)
 		g_string_append_printf (command, "export LC_ALL=\"%s\" && ", lc_all);
 	else if (lc_messages)
@@ -308,6 +309,16 @@
 		g_string_append_printf (command, "export LANG=\"%s\" && ", lang);
 	else if (language)
 		g_string_append_printf (command, "export LANGUAGE=\"%s\" && ", language);
+#else
+	if (lc_all)
+		g_string_append_printf (command, "env LC_ALL=\"%s\" ", lc_all);
+	else if (lc_messages)
+		g_string_append_printf (command, "env LC_MESSAGES=\"%s\" ", lc_messages);
+	else if (lang)
+		g_string_append_printf (command, "env LANG=\"%s\" ", lang);
+	else if (language)
+		g_string_append_printf (command, "env LANGUAGE=\"%s\" ", language);
+#endif
 }
 
 void
