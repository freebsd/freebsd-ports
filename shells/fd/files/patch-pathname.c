--- pathname.c.orig	Wed Jun  9 00:00:00 2004
+++ pathname.c	Sun Jun 13 01:48:43 2004
@@ -141,7 +141,7 @@
 
 static char *NEAR getenvvar __P_((char *, int));
 static int NEAR setvar __P_((char *, char *, int));
-static int NEAR ismeta __P_((char *s, int, int, int));
+static int NEAR ismeta __P_((char *s, int, int, int, int));
 #ifdef	_NOORIGGLOB
 static char *NEAR cnvregexp __P_((char *, int));
 #else
@@ -820,9 +820,9 @@
 	return(s);
 }
 
-static int NEAR ismeta(s, ptr, quote, len)
+static int NEAR ismeta(s, ptr, quote, len, flags)
 char *s;
-int ptr, quote, len;
+int ptr, quote, len, flags;
 {
 #ifdef	FAKEMETA
 	return(0);
@@ -830,7 +830,7 @@
 	if (s[ptr] != PMETA || quote == '\'') return(0);
 
 	if (len >= 0) {
-		if (ptr + 1 >= len) return(0);
+		if (!(flags & EA_EOLMETA) && ptr + 1 >= len) return(0);
 # ifndef	BASHSTYLE
 	/* bash does not treat "\" as \ */
 		if (quote == '"' && s[ptr + 1] == quote && ptr + 2 >= len)
@@ -838,7 +838,7 @@
 # endif
 	}
 	else {
-		if (!s[ptr + 1]) return(0);
+		if (!(flags & EA_EOLMETA) && !s[ptr + 1]) return(0);
 # ifndef	BASHSTYLE
 	/* bash does not treat "\" as \ */
 		if (quote == '"' && s[ptr + 1] == quote && !s[ptr + 2])
@@ -884,7 +884,7 @@
 			re[j++] = s[i];
 			continue;
 		}
-		else if (ismeta(s, i, '\0', len)) {
+		else if (ismeta(s, i, '\0', len, 0)) {
 			re[j++] = s[i++];
 			re[j++] = s[i];
 		}
@@ -2183,7 +2183,7 @@
 #endif
 	else if (*qp == '\'') return(PC_SQUOTE);
 	else if (spc && *s == spc) return(*s);
-	else if (ismeta(s, 0, *qp, len)) return(PC_META);
+	else if (ismeta(s, 0, *qp, len, flags)) return(PC_META);
 #ifdef	BASHSTYLE
 	/* bash can include `...` in "..." */
 	else if ((flags & EA_BACKQ) && *s == '`') {
