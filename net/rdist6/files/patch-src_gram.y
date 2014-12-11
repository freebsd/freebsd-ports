This patch replaces the character-buffer (which needed to be static,
BTW) with a dynamically (re)allocated one.

This reduces the memory requirements in most cases, while still
allowing LARGE lines to be properly processed.

While here, make the error-reporting a tad more useful to people
debugging their distfiles.

	-mi

--- src/gram.y	1998-11-09 23:10:42.000000000 -0500
+++ src/gram.y	2014-12-04 12:32:45.000000000 -0500
@@ -61,4 +61,8 @@
 
 #include "defs.h"
+static char * xappend(char *str, size_t *len, char c);
+void yyerror(const char *message);
+static char *yytext;
+static size_t yytextlen;
 
 static struct namelist *addnl(), *subnl(), *andnl();
@@ -241,10 +245,12 @@
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
@@ -286,11 +292,5 @@
 
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
@@ -298,5 +298,5 @@
 			if (c == '\\') {
 				if ((c = getc(fin)) == EOF) {
-					*cp1++ = '\\';
+					yytext = xappend(yytext, &yytextlen, '\\');
 					break;
 				}
@@ -306,10 +306,9 @@
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
 
@@ -320,21 +319,16 @@
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
@@ -343,10 +337,14 @@
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
@@ -398,5 +396,5 @@
 		c = CMDSPECIAL;
 	else {
-		yylval.string = makestr(yytext);
+		yylval.string = yytext;
 		return(NAME);
 	}
@@ -422,4 +420,5 @@
  * Insert or append ARROW command to list of hosts to be updated.
  */
+void
 insert(label, files, hosts, subcmds)
 	char *label;
@@ -476,4 +475,5 @@
  * executed in the order they appear in the distfile.
  */
+static void
 append(label, files, stamp, subcmds)
 	char *label;
@@ -502,22 +502,28 @@
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
