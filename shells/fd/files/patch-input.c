diff -u ../old/FD-2.00b/input.c ./input.c
--- ../old/FD-2.00b/input.c	Wed Mar 27 00:00:00 2002
+++ ./input.c	Fri Apr 12 12:01:19 2002
@@ -1047,8 +1047,11 @@
 char *s;
 int cx, len, plen, max, linemax, comline, cont;
 {
+# if	!MSDOS || !defined (_NOORIGSHELL)
+	int bq;
+# endif
 	char *cp1, *cp2, **argv;
-	int i, l, ins, top, fix, argc, quote, quoted;
+	int i, l, ins, top, fix, argc, quote, quoted, hasmeta;
 
 	if (selectlist && cont > 0) {
 		selectfile(tmpfilepos++, NULL);
@@ -1056,17 +1059,26 @@
 		return(0);
 	}
 
-	for (i = top = 0, quote = '\0'; i < cx; i++) {
-		if (s[i] == quote) quote = '\0';
+# if	!MSDOS || !defined (_NOORIGSHELL)
+	bq = 0;
+# endif
+	quote = '\0';
+	quoted = 0;
+	for (i = top = 0; i < cx; i++) {
+		if (s[i] == quote) {
+			if (quote == '"') quoted = i;
+# if	!MSDOS || !defined (_NOORIGSHELL)
+			if (quote == '\'') quoted = i;
+# endif
+			quote = '\0';
+		}
 		else if (iskanji1(s, i)) i++;
 		else if (quote);
-# if	MSDOS && defined (_NOORIGSHELL)
 		else if (s[i] == '"') quote = s[i];
-# else
-		else if (s[i] == '"' || s[i] == '\'') quote = s[i];
+# if	!MSDOS || !defined (_NOORIGSHELL)
+		else if (s[i] == '\'') quote = s[i];
 		else if (s[i] == '`') {
-			top = i + 1;
-			quote = s[i];
+			if ((bq = 1 - bq)) top = i + 1;
 		}
 # endif
 		else if (s[i] == '=' || strchr(CMDLINE_DELIM, s[i]))
@@ -1076,13 +1088,6 @@
 		putterm(t_bell);
 		return(0);
 	}
-# if	MSDOS && defined (_NOORIGSHELL)
-	quoted = (!quote && cx > 0 && s[cx - 1] == '"')
-# else
-	if (quote == '`') quote = '\0';
-	quoted = (!quote && cx > 0 && s[cx - 1] == '"' || s[cx - 1] == '\'')
-# endif
-		? s[cx - 1] : '\0';
 	if (comline && top > 0) {
 		for (i = top - 1; i >= 0; i--)
 			if (s[i] != ' ' && s[i] != '\t') break;
@@ -1092,6 +1097,14 @@
 	cp1 = malloc2(cx - top + 1);
 	strncpy2(cp1, s + top, cx - top);
 	cp1 = evalpath(cp1, 1);
+	hasmeta = 0;
+	for (i = 0; cp1[i]; i++) {
+		if (strchr(METACHAR, cp1[i])) {
+			hasmeta = 1;
+			break;
+		}
+		if (iskanji1(cp1, i)) i++;
+	}
 
 	if (selectlist && cont < 0) {
 		argv = (char **)malloc2(1 * sizeof(char *));
@@ -1128,13 +1141,11 @@
 	}
 
 	cp1 = findcommon(argc, argv);
-	fix = 0;
-	if (argc == 1 && cp1) {
-		if (isdelim(cp1, (int)strlen(cp1) - 1)) fix--;
-		else fix++;
-	}
+	fix = '\0';
+	if (argc == 1 && cp1)
+		fix = ((cp2 = strrdelim(cp1, 0)) && !*(cp2 + 1)) ? _SC_ : ' ';
 
-	if (!cp1 || ((ins = (int)strlen(cp1) - ins) <= 0 && fix <= 0)) {
+	if (!cp1 || ((ins = (int)strlen(cp1) - ins) <= 0 && fix != ' ')) {
 		if (cont <= 0) {
 			putterm(t_bell);
 			l = 0;
@@ -1157,12 +1168,25 @@
 	free(argv);
 
 	l = 0;
-	if (!quote && !quoted && len < max) {
-		for (i = 0; cp1[i]; i++) {
-			if (strchr(METACHAR, cp1[i])) break;
-			if (iskanji1(cp1, i)) i++;
+	if (!hasmeta) for (i = 0; cp1[i]; i++) {
+		if (strchr(METACHAR, cp1[i])) {
+			hasmeta = 1;
+			break;
+		}
+		if (iskanji1(cp1, i)) i++;
+	}
+
+	if (hasmeta) {
+		if (quote);
+		else if (quoted) {
+			quote = s[quoted];
+			setcursor(vlen(s, quoted), plen, max, linemax);
+			deletechar(s, quoted, len, plen, max, linemax, 1);
+			delshift(s, quoted, len--, 1);
+			l--;
+			setcursor(vlen(s, --cx), plen, max, linemax);
 		}
-		if (cp1[i]) {
+		else if (len < max) {
 			setcursor(vlen(s, top), plen, max, linemax);
 			insertchar(s, top, len, plen, max, linemax, 1);
 			insshift(s, top, len++, 1);
@@ -1171,43 +1195,30 @@
 			putch2(quote);
 			setcursor(vlen(s, ++cx), plen, max, linemax);
 		}
+		else hasmeta = 0;
 	}
 
 	cp2 = cp1 + (int)strlen(cp1) - ins;
-	if (quote && fix < 0 && len + 1 < max) {
-		i = insertstr(s, cx, len, plen,
-			max, linemax, cp2, ins - 1, quote);
-		l += i;
+	if (fix == _SC_) {
+		ins--;
+		if (!hasmeta) quote = '\0';
+	}
+	i = insertstr(s, cx, len, plen, max, linemax, cp2, ins, quote);
+	l += i;
+	if (fix && (len += i) < max) {
 		cx += i;
-		insertchar(s, cx, len, plen, max, linemax, 1);
-		insshift(s, cx, len++, 1);
-		l++;
-		s[cx++] = quote;
-		putcursor(quote, 1);
-		insertchar(s, cx, len, plen, max, linemax, 1);
-		insshift(s, cx, len, 1);
-		l++;
-		s[cx] = _SC_;
-		putcursor(_SC_, 1);
-	}
-	else {
-		i = insertstr(s, cx, len, plen, max, linemax, cp2, ins, quote);
-		l += i;
-		if (fix > 0 && (len += i) < max) {
-			cx += i;
-			if (quote && len + 1 < max) {
-				insertchar(s, cx, len, plen, max, linemax, 1);
-				insshift(s, cx, len++, 1);
-				l++;
-				s[cx++] = quote;
-				putcursor(quote, 1);
-			}
+		if (quote && len + 1 < max) {
 			insertchar(s, cx, len, plen, max, linemax, 1);
-			insshift(s, cx, len, 1);
+			insshift(s, cx, len++, 1);
 			l++;
-			s[cx] = ' ';
-			putcursor(' ', 1);
+			s[cx++] = quote;
+			putcursor(quote, 1);
 		}
+		insertchar(s, cx, len, plen, max, linemax, 1);
+		insshift(s, cx, len, 1);
+		l++;
+		s[cx] = fix;
+		putcursor(fix, 1);
 	}
 
 	free(cp1);
