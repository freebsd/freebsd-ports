--- src/prefs_common.c	2008/04/24 05:39:34	1.204.2.167
+++ src/prefs_common.c	2008/05/04 15:59:02	1.204.2.168
@@ -226,7 +226,7 @@
 	 NULL, NULL, NULL},
 	{"compose_subject_format", "",
 	 &prefs_common.compose_subject_format, P_STRING, NULL, NULL, NULL},
-	{"compose_body_format", NULL,
+	{"compose_body_format", N_("Hello,\\n"),
 	 &prefs_common.compose_body_format, P_STRING, NULL, NULL, NULL},
 
 	{"linewrap_length", "72", &prefs_common.linewrap_len, P_INT,
@@ -293,12 +293,16 @@
 	/* Quote */
 	{"reply_quote_mark", "> ", &prefs_common.quotemark, P_STRING,
 	 NULL, NULL, NULL},
-	{"reply_quote_format", NULL,
+	{"reply_quote_format", N_("On %d\\n%f wrote:\\n\\n%q"),
 	 &prefs_common.quotefmt, P_STRING, NULL, NULL, NULL},
 
 	{"forward_quote_mark", "> ", &prefs_common.fw_quotemark, P_STRING,
 	 NULL, NULL, NULL},
-	{"forward_quote_format", NULL, &prefs_common.fw_quotefmt, P_STRING,
+	{"forward_quote_format",
+	 N_("\\n\\nBegin forwarded message:\\n\\n"
+ 	 "?d{Date: %d\\n}?f{From: %f\\n}?t{To: %t\\n}?c{Cc: %c\\n}"
+ 	 "?n{Newsgroups: %n\\n}?s{Subject: %s\\n}\\n\\n%M"),
+	 &prefs_common.fw_quotefmt, P_STRING,
 	 NULL, NULL, NULL},
 	{"quote_chars", ">", &prefs_common.quote_chars, P_STRING,
 	 NULL, NULL, NULL},

