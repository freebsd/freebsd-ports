--- Src/Zle/zle_refresh.c.orig	Mon Sep 10 19:48:51 2001
+++ Src/Zle/zle_refresh.c	Thu May  9 08:36:47 2002
@@ -647,7 +647,11 @@
 static void
 refreshline(int ln)
 {
+#ifdef ZSH_EUC
+    unsigned char *nl, *ol, *p1;	/* line buffer pointers		 */
+#else
     char *nl, *ol, *p1;		/* line buffer pointers			 */
+#endif
     int ccs = 0,		/* temporary count for cursor position	 */
 	char_ins = 0,		/* number of characters inserted/deleted */
 	col_cleareol,		/* clear to end-of-line from this column */
@@ -753,7 +757,32 @@
     for (;;) {
 	if (*nl && *ol && nl[1] == ol[1]) /* skip only if second chars match */
 	/* skip past all matching characters */
+#ifdef ZSH_EUC
+	{
+	    if (locale_is_euc) {
+		for (; *nl && (*nl == *ol); nl++, ol++, ccs++) {
+		    if (_mbmap_euc[*nl] & _MB1) {
+			if (*(ol+1) == '\0')
+			    continue;
+			if (_mbmap_euc[*(nl+1)] & _MB2) {
+			    if (*(nl+1) != *(ol+1))
+				break;
+			    else {
+				nl++;
+				ol++;
+				ccs++;
+			    }
+			} else if (*(nl+1) == '\0') {
+			    continue;
+			}
+		    }
+		}
+	    } else
+#endif
 	    for (; *nl && (*nl == *ol); nl++, ol++, ccs++) ;
+#ifdef ZSH_EUC
+	}
+#endif
 
 	if (!*nl) {
 	    if (ccs == winw && hasam && char_ins > 0 && ins_last
