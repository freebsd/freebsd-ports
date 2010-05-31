--- relayctl/parser.c.orig	2010-05-31 07:38:49.928320202 +0000
+++ relayctl/parser.c	2010-05-31 07:41:05.348576930 +0000
@@ -68,6 +68,7 @@
 static const struct token t_rdr_id[];
 static const struct token t_table_id[];
 static const struct token t_host_id[];
+static const struct token t_log[];
 
 static const struct token t_main[] = {
 	{KEYWORD,	"monitor",	MONITOR,	NULL},
@@ -78,6 +79,7 @@
 	{KEYWORD,	"redirect",	NONE,		t_rdr},
 	{KEYWORD,	"table",	NONE,		t_table},
 	{KEYWORD,	"host",		NONE,		t_host},
+	{KEYWORD,	"log",		NONE,		t_log},
 	{ENDTOKEN,	"",		NONE,		NULL}
 };
 
@@ -126,11 +128,17 @@
 	{ENDTOKEN,	"",		NONE,		NULL}
 };
 
+static const struct token t_log[] = {
+	{KEYWORD,	"verbose",	LOG_VERBOSE, 	NULL},
+	{KEYWORD,	"brief",	LOG_BRIEF, 	NULL},
+	{ENDTOKEN, 	"",		NONE,		NULL}
+};
+
 static struct parse_result	res;
 
 #ifdef __FreeBSD__
-const struct token	*match_token(const char *, const struct token []);
-void			show_valid_args(const struct token []);
+const struct token	*match_token(const char *, const struct token *);
+void			show_valid_args(const struct token *);
 #endif
 
 struct parse_result *
@@ -166,7 +174,7 @@
 }
 
 const struct token *
-match_token(const char *word, const struct token table[])
+match_token(const char *word, const struct token *table)
 {
 	u_int			 i, match;
 	const struct token	*t = NULL;
@@ -243,7 +251,7 @@
 }
 
 void
-show_valid_args(const struct token table[])
+show_valid_args(const struct token *table)
 {
 	int	i;
 
