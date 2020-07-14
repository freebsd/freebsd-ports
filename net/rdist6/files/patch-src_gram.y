This patch replaces the character-buffer (which needed to be static,
BTW) with a dynamically (re)allocated one.

This reduces the memory requirements in most cases, while still
allowing LARGE lines to be properly processed.

While here, make the error-reporting a tad more useful to people
debugging their distfiles.

	-mi

--- src/gram.y.orig	1998-11-10 04:10:42 UTC
+++ src/gram.y
@@ -61,6 +61,13 @@ static char copyright[] =
 
 #include "defs.h"
 
+#define	yylex	rdist_yylex
+
+static char * xappend(char *str, size_t *len, char c);
+void yyerror(const char *message);
+static char *yytext;
+static size_t yytextlen;
+
 static struct namelist *addnl(), *subnl(), *andnl();
 struct	cmd *cmds = NULL;
 struct	cmd *last_cmd;
@@ -240,12 +247,14 @@ opt_namelist:	  /* VOID */ = {
 int	yylineno = 1;
 extern	FILE *fin;
 
+static int
 yylex()
 {
-	static char yytext[INMAX];
 	register int c;
-	register char *cp1, *cp2;
 	static char quotechars[] = "[]{}*?$";
+
+	yytext = NULL;
+	yytextlen = 0;
 	
 again:
 	switch (c = getc(fin)) {
@@ -285,19 +294,13 @@ again:
 		break;
 
 	case '"':  /* STRING */
-		cp1 = yytext;
-		cp2 = &yytext[INMAX - 1];
 		for (;;) {
-			if (cp1 >= cp2) {
-				yyerror("command string too long\n");
-				break;
-			}
 			c = getc(fin);
 			if (c == EOF || c == '"')
 				break;
 			if (c == '\\') {
 				if ((c = getc(fin)) == EOF) {
-					*cp1++ = '\\';
+					yytext = xappend(yytext, &yytextlen, '\\');
 					break;
 				}
 			}
@@ -305,12 +308,11 @@ again:
 				yylineno++;
 				c = ' '; /* can't send '\n' */
 			}
-			*cp1++ = c;
+			yytext = xappend(yytext, &yytextlen, c);
 		}
 		if (c != '"')
 			yyerror("missing closing '\"'\n");
-		*cp1 = '\0';
-		yylval.string = makestr(yytext);
+		yylval.string = xappend(yytext, &yytextlen, '\0');
 		return(STRING);
 
 	case ':':  /* : or :: */
@@ -319,35 +321,34 @@ again:
 		(void) ungetc(c, fin);
 		return(COLON);
 	}
-	cp1 = yytext;
-	cp2 = &yytext[INMAX - 1];
 	for (;;) {
-		if (cp1 >= cp2) {
-			yyerror("input line too long\n");
-			break;
-		}
 		if (c == '\\') {
 			if ((c = getc(fin)) != EOF) {
 				if (any(c, quotechars))
-					*cp1++ = QUOTECHAR;
+					yytext = xappend(yytext, &yytextlen,
+					    QUOTECHAR);
 			} else {
-				*cp1++ = '\\';
+				yytext = xappend(yytext, &yytextlen, '\\');
 				break;
 			}
 		}
-		*cp1++ = c;
+		yytext = xappend(yytext, &yytextlen, c);
 		c = getc(fin);
 		if (c == EOF || any(c, " \"'\t()=;:\n")) {
 			(void) ungetc(c, fin);
 			break;
 		}
 	}
-	*cp1 = '\0';
-	if (yytext[0] == '-' && yytext[1] == CNULL) 
+	if (yytext == NULL) {
+		yylval.string = NULL;
+		return(NAME);
+	}
+	yytext = xappend(yytext, &yytextlen, '\0');
+	if (yytextlen == 2 && yytext[0] == '-') 
 		return '-';
 	if (yytext[0] == '-' && parendepth <= 0) {
 		opt_t opt = 0;
-		static char ebuf[BUFSIZ];
+		char ebuf[BUFSIZ];
 
 		switch (yytext[1]) {
 		case 'o':
@@ -397,7 +398,7 @@ again:
 	else if (!strcmp(yytext, "cmdspecial"))
 		c = CMDSPECIAL;
 	else {
-		yylval.string = makestr(yytext);
+		yylval.string = yytext;
 		return(NAME);
 	}
 	yylval.subcmd = makesubcmd(c);
@@ -421,6 +422,7 @@ extern int any(c, str)
 /*
  * Insert or append ARROW command to list of hosts to be updated.
  */
+void
 insert(label, files, hosts, subcmds)
 	char *label;
 	struct namelist *files, *hosts;
@@ -475,6 +477,7 @@ insert(label, files, hosts, subcmds)
  * Append DCOLON command to the end of the command list since these are always
  * executed in the order they appear in the distfile.
  */
+static void
 append(label, files, stamp, subcmds)
 	char *label;
 	struct namelist *files;
@@ -501,24 +504,30 @@ append(label, files, stamp, subcmds)
 /*
  * Error printing routine in parser.
  */
+void
 yyerror(s)
-	char *s;
+	const char *s;
 {
-	error("Error in distfile: line %d: %s", yylineno, s);
+	error("Error in distfile: line %d: %s (offending text: %.*s%s)",
+	    yylineno, s, 11, yytextlen > 0 ? yytext : "<empty>",
+	    yytextlen > 11 ? " ..." : "");
 }
 
 /*
- * Return a copy of the string.
+ * Append character to a string of given length. Return
+ * the new string, which -- depending on realloc -- may
+ * or may not have the same address now.
  */
-char *
-makestr(str)
-	char *str;
+static char *
+xappend(char *str, size_t *len, char c)
 {
 	char *cp;
 
-	cp = strdup(str);
+	cp = realloc(str, *len + 1);
 	if (cp == NULL)
 		fatalerr("ran out of memory");
+	cp[*len] = c;
+	(*len)++;
 
 	return(cp);
 }
