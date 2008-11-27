--- ospfctl/parser.h.orig	2008-02-07 19:12:58.000000000 +0300
+++ ospfctl/parser.h	2008-02-07 19:15:45.000000000 +0300
@@ -50,6 +50,16 @@
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
 struct parse_result {
 	struct in_addr	addr;
 	char		ifname[IF_NAMESIZE];
@@ -58,6 +68,13 @@
 	u_int8_t	prefixlen;
 };
 
+struct token {
+	enum token_type		 type;
+	const char		*keyword;
+	int			 value;
+	const struct token	*next;
+};
+
 struct parse_result	*parse(int, char *[]);
 const struct token	*match_token(const char *, const struct token []);
 void			 show_valid_args(const struct token []);
