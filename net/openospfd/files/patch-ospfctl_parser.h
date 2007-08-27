--- ospfctl/parser.h.orig	Fri Jul 27 15:11:55 2007
+++ ospfctl/parser.h	Fri Jul 27 15:12:01 2007
@@ -50,6 +50,23 @@
 	RELOAD
 };
 
+enum token_type {
+	NOTOKEN,
+	ENDTOKEN,
+	KEYWORD,
+	ADDRESS,
+	FLAG,
+	PREFIX,
+	IFNAME
+};
+
+struct token {
+	enum token_type		 type;
+	const char		*keyword;
+	int			 value;
+	const struct token	*next;
+};
+
 struct parse_result {
 	struct in_addr	addr;
 	char		ifname[IF_NAMESIZE];
