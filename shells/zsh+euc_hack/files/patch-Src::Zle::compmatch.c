--- Src/Zle/compmatch.c.orig	Tue Feb 10 11:30:14 2004
+++ Src/Zle/compmatch.c	Thu Mar 25 19:51:03 2004
@@ -1313,6 +1313,9 @@
     while (la && lb) {
 	if (*sa != *sb) {
 	    /* Different characters, try the matchers. */
+#ifdef ZSH_EUC
+ono:
+#endif
 	    for (t = 0, ms = bmatchers; ms && !t; ms = ms->next) {
 		mp = ms->matcher;
 		if (mp && !mp->flags && mp->wlen > 0 && mp->llen > 0 &&
@@ -1358,6 +1361,13 @@
 	    }
 	    if (!t)
 		break;
+#ifdef ZSH_EUC
+	} else if (locale_is_euc &&
+	  (_mbmap_euc[*(unsigned char*)sa] & _MB1) &&
+	  (_mbmap_euc[*((unsigned char*)sa+1)] & _MB2) &&
+	  *(sa+1) != *(sb+1)) {
+	    goto ono;
+#endif
 	} else {
 	    /* Same character, just take it. */
 	    if (rr <= 1) {
@@ -1589,6 +1599,30 @@
 	 * characters, at this stage we still need the overall length
 	 * including Meta's as separate characters.
 	 */
+#ifdef ZSH_EUC
+	if (locale_is_euc) {
+	    if (sfx)
+		for (l = 0, p = str, q = md->str;
+		     l < len && l < md->len && p[ind] == q[ind];
+		     l++, p += add, q += add);
+	    else
+		for (l = 0, p = str, q = md->str;;) {
+		    if (!(l < len && l < md->len))
+			break;
+
+		    if ((_mbmap_euc[*(unsigned char*)p] & _MB1) && (_mbmap_euc[*((unsigned char*)p+1)] & _MB2)) {
+			if (*p == *q && *(p+1) == *(q+1)) {
+			    l+=2, p+=2, q+=2;
+			} else
+			    break;
+		    } else {
+			if (*p != *q)
+			    break;
+			l++, p++, q++;
+		    }
+		}
+	} else
+#endif
 	for (l = 0, p = str, q = md->str;
 	     l < len && l < md->len && p[ind] == q[ind];
 	     l++, p += add, q += add) {}
