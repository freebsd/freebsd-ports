--- relayctl/parser.h.orig	2010-05-31 07:38:49.934576348 +0000
+++ relayctl/parser.h	2010-05-31 07:40:47.494152077 +0000
@@ -32,7 +32,9 @@
 	SHUTDOWN,
 	POLL,
 	RELOAD,
-	MONITOR
+	MONITOR,
+	LOG_VERBOSE,
+	LOG_BRIEF
 };
 
 struct parse_result {
@@ -42,6 +44,6 @@
 
 struct parse_result	*parse(int, char *[]);
 #ifndef __FreeBSD__
-const struct token      *match_token(const char *, const struct token []);
-void                     show_valid_args(const struct token []);
+const struct token      *match_token(const char *, const struct token *);
+void                     show_valid_args(const struct token *);
 #endif
