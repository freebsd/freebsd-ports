
$FreeBSD$

--- pan/message-send.c	2001/08/22 18:36:41	1.1
+++ pan/message-send.c	2001/08/22 18:36:50
@@ -25,7 +25,7 @@
 #include <string.h>
 #include <sys/types.h>
 
-#include <langinfo.h>
+#include <locale.h>
 
 #include <glib.h>
 
@@ -75,6 +75,7 @@
 		   gboolean         force_new_message_id)
 {
 	gchar * tmp;
+	gchar * s;
 	const gchar * pch;
 	debug_enter ("build_nntp_header");
 
@@ -153,9 +154,10 @@
 
 	/* Add mime header, charset type, encoding type */
 	g_string_append (postme, "Mime-Version: 1.0\r\n");
-	pch = nl_langinfo (CODESET);
-	if (!is_nonempty_string (pch))
-		pch = "ISO-8859-1";
+	pch = "ISO-8859-1";
+	if ((s = setlocale(LC_CTYPE, NULL)) != NULL)
+		if ((s = strchr(s, '.')) != NULL)
+			pch = s + 1;
 	g_string_sprintfa (postme, "Content-Type: text/plain; charset=%s\r\n", pch);
 	g_string_append (postme, "Content-Transfer-Encoding: 8bit\r\n");
 
