A patch taken from: [FDclone-users:00020]

diff -u ../old/FD-2.01b/input.c ./input.c
--- ../old/FD-2.01b/input.c	Wed Jul 10 00:00:00 2002
+++ ./input.c	Mon Jul 29 14:54:00 2002
@@ -1052,7 +1052,7 @@
 int cx, len, plen, max, linemax, comline, cont;
 {
 # if	!MSDOS || !defined (_NOORIGSHELL)
-	int bq;
+	int bq, hadmeta;
 # endif
 	char *cp1, *cp2, **argv;
 	int i, l, ins, top, fix, argc, quote, quoted, hasmeta;
@@ -1064,7 +1064,7 @@
 	}
 
 # if	!MSDOS || !defined (_NOORIGSHELL)
-	bq = 0;
+	bq = hadmeta = 0;
 # endif
 	quote = '\0';
 	quoted = 0;
@@ -1077,6 +1077,13 @@
 			quote = '\0';
 		}
 		else if (iskanji1(s, i)) i++;
+# if	!MSDOS || !defined (_NOORIGSHELL)
+		else if (quote == '\'');
+		else if (isnmeta(s, i, quote, cx)) {
+			i++;
+			hadmeta++;
+		}
+# endif
 		else if (quote);
 		else if (s[i] == '"') quote = s[i];
 # if	!MSDOS || !defined (_NOORIGSHELL)
@@ -1182,8 +1189,23 @@
 	}
 
 	if (hasmeta) {
+		char *tmp, *home;
+		int hlen;
+
+		if (quote || quoted > top || s[top] != '~') {
+			home = NULL;
+			i = hlen = 0;
+		}
+		else {
+			tmp = &(s[top]);
+			s[len] = '\0';
+			home = malloc2(len - top + 1);
+			hlen = evalhome(&home, 0, &tmp);
+			i = ++tmp - &(s[top]);
+		}
+
 		if (quote);
-		else if (quoted) {
+		else if (quoted > top) {
 			quote = s[quoted];
 			setcursor(vlen(s, quoted), plen, max, linemax);
 			deletechar(s, quoted, len, plen, max, linemax, 1);
@@ -1191,7 +1213,35 @@
 			l--;
 			setcursor(vlen(s, --cx), plen, max, linemax);
 		}
-		else if (len < max) {
+		else if (len + hlen - i < max) {
+			if (home) {
+				setcursor(vlen(s, top), plen, max, linemax);
+				deletechar(s, top, len, plen, max, linemax, i);
+				delshift(s, top, len, i);
+				len -= i;
+				l -= i;
+				cx -= i;
+				i = insertstr(s, top, len, plen, max, linemax,
+					home, hlen, '\0');
+				len += i;
+				l += i;
+				cx += i;
+				free(home);
+			}
+# if	!MSDOS || !defined (_NOORIGSHELL)
+			if (hadmeta) for (i = top; i < cx; i++) {
+				if (iskanji1(s, i)) {
+					i++;
+					continue;
+				}
+				if (!isnmeta(s, i, '\0', cx)) continue;
+				setcursor(vlen(s, i), plen, max, linemax);
+				deletechar(s, i, len, plen, max, linemax, 1);
+				delshift(s, i, len--, 1);
+				l--;
+				cx--;
+			}
+# endif	/* !MSDOS || !_NOORIGSHELL */
 			setcursor(vlen(s, top), plen, max, linemax);
 			insertchar(s, top, len, plen, max, linemax, 1);
 			insshift(s, top, len++, 1);
diff -u ../old/FD-2.01b/pathname.c ./pathname.c
--- ../old/FD-2.01b/pathname.c	Wed Jul 10 00:00:00 2002
+++ ./pathname.c	Mon Jul 29 13:40:14 2002
@@ -178,7 +178,6 @@
 static int NEAR replacevar __P_((char *, char **, int, int, int, int));
 static char *NEAR insertarg __P_((char *, int, char *, int, int));
 static int NEAR evalvar __P_((char **, int, char **, int));
-static int NEAR evalhome __P_((char **, int, char **));
 
 #ifdef	LSI_C
 #include <jctype.h>
@@ -2480,7 +2479,7 @@
 	return(NULL);
 }
 
-static int NEAR evalhome(bufp, ptr, argp)
+int evalhome(bufp, ptr, argp)
 char **bufp;
 int ptr;
 char **argp;
diff -u ../old/FD-2.01b/pathname.h ./pathname.h
--- ../old/FD-2.01b/pathname.h	Wed Jul 10 00:00:00 2002
+++ ./pathname.h	Mon Jul 29 13:39:48 2002
@@ -161,6 +161,7 @@
 # endif
 #endif
 extern char *gethomedir __P_((VOID_A));
+extern int evalhome __P_((char **, int, char **));
 extern char *evalarg __P_((char *, int, int));
 extern int evalifs __P_((int, char ***, char *));
 extern int evalglob __P_((int, char ***, int));

A patch taken from: [FDclone-users:00035]

diff -u old/input.c ./input.c
--- old/input.c	Wed Aug 21 14:19:15 2002
+++ ./input.c	Wed Aug 21 14:08:27 2002
@@ -852,52 +852,78 @@
 	dupl = malloc2(ins * 2 + 1);
 	insertchar(s, cx, len, plen, max, linemax, vlen(strins, ins));
 	insshift(s, cx, len, ins);
+	for (i = 0; i < ins; i++) s[cx + i] = ' ';
+	len += ins;
 	for (i = j = 0; i < ins; i++, j++) {
 		if (isctl(strins[i])) {
-			if (len + ins + j - i >= max)
+			if (len + j - i >= max)
 				dupl[j] = s[cx + j] = '?';
 			else {
+				insertchar(s, cx, len, plen, max, linemax, 1);
+				insshift(s, cx + j, len, 1);
 				dupl[j] = '^';
 				s[cx + j] = QUOTE;
-				dupl[++j] = (strins[i] + '@') & 0x7f;
+				j++;
+				dupl[j] = (strins[i] + '@') & 0x7f;
 				s[cx + j] = strins[i];
 			}
 		}
 #ifdef	CODEEUC
 		else if (isekana(strins, i)) {
-			if (len + ins + j - i >= max)
+			if (len + j - i >= max)
 				dupl[j] = s[cx + j] = '?';
 			else {
 				dupl[j] = s[cx + j] = strins[i];
-				dupl[j + 1] = s[cx + j + 1] = strins[++i];
 				j++;
+				dupl[j] = s[cx + j] = strins[++i];
 			}
 		}
 #endif
 		else if (iskanji1(strins, i)) {
-			if (len + ins + j - i >= max)
+			if (len + j - i >= max)
 				dupl[j] = s[cx + j] = '?';
 			else {
 				dupl[j] = s[cx + j] = strins[i];
-				dupl[j + 1] = s[cx + j + 1] = strins[++i];
 				j++;
+				dupl[j] = s[cx + j] = strins[++i];
 			}
 		}
 #if	MSDOS && defined (_NOORIGSHELL)
-		else if (strchr(DQ_METACHAR, strins[i])) {
+		else if (strchr(DQ_METACHAR, strins[i])
 #else
-		else if (quote == '"' && strchr(DQ_METACHAR, strins[i])) {
+		else if ((quote == '\'' && strins[i] == '\'')
+		|| (quote == '"' && strins[i] == '!')) {
+			f = 3;
+			if (!strins[i + 1]) f--;
+			if (len + j - i + f > max)
+				dupl[j] = s[cx + j] = '?';
+			else {
+				insertchar(s, cx, len, plen, max, linemax, f);
+				insshift(s, cx + j, len, f);
+				dupl[j] = s[cx + j] = quote;
+				j++;
+				dupl[j] = s[cx + j] = PMETA;
+				j++;
+				dupl[j] = s[cx + j] = strins[i];
+				j++;
+				dupl[j] = s[cx + j] = quote;
+			}
+		}
+		else if ((quote == '"' && strchr(DQ_METACHAR, strins[i]))
 #endif
-			if (len + ins + j - i >= max)
+		|| (!quote && strchr(METACHAR, strins[i]))) {
+			if (len + j - i >= max)
 				dupl[j] = s[cx + j] = '?';
 			else {
+				insertchar(s, cx, len, plen, max, linemax, 1);
+				insshift(s, cx + j, len, 1);
 #if	MSDOS && defined (_NOORIGSHELL)
-				dupl[j] = s[cx + j] =
+				dupl[j] = s[cx + j] = strins[i];
 #else
 				dupl[j] = s[cx + j] = PMETA;
 #endif
-				dupl[j + 1] = s[cx + j + 1] = strins[i];
 				j++;
+				dupl[j] = s[cx + j] = strins[i];
 			}
 		}
 		else dupl[j] = s[cx + j] = strins[i];
@@ -1235,6 +1261,7 @@
 					continue;
 				}
 				if (!isnmeta(s, i, '\0', cx)) continue;
+				if (strchr(DQ_METACHAR, s[i + 1])) continue;
 				setcursor(vlen(s, i), plen, max, linemax);
 				deletechar(s, i, len, plen, max, linemax, 1);
 				delshift(s, i, len--, 1);
@@ -1254,15 +1281,12 @@
 	}
 
 	cp2 = cp1 + (int)strlen(cp1) - ins;
-	if (fix == _SC_) {
-		ins--;
-		if (!hasmeta) quote = '\0';
-	}
+	if (fix == _SC_) ins--;
 	i = insertstr(s, cx, len, plen, max, linemax, cp2, ins, quote);
 	l += i;
 	if (fix && (len += i) < max) {
 		cx += i;
-		if (quote && len + 1 < max) {
+		if (quote && len + 1 < max && (fix != _SC_ || hasmeta)) {
 			insertchar(s, cx, len, plen, max, linemax, 1);
 			insshift(s, cx, len++, 1);
 			l++;
