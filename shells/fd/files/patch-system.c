--- system.c.orig	Wed Jun  9 00:00:00 2004
+++ system.c	Sun Jun 13 01:55:23 2004
@@ -5795,11 +5795,12 @@
 			}
 		}
 
-		pc = parsechar(&(s[i]), -1,
+		pc = parsechar(&(s[i]), -1, '$', EA_BACKQ | EA_EOLMETA,
 #ifdef	BASHSTYLE
-			'$', EA_BACKQ, &(rp -> new), &(rp -> old));
+	/* bash can include `...` in "..." */
+			&(rp -> new), &(rp -> old));
 #else
-			'$', EA_BACKQ, &(rp -> new), NULL);
+			&(rp -> new), NULL);
 #endif
 
 		if (pc == PC_OPQUOTE || pc == PC_CLQUOTE || pc == PC_SQUOTE)
