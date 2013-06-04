--- icb/c_hush.c.orig
+++ icb/c_hush.c
@@ -23,7 +23,7 @@
 	while (*nick == ' ' || *nick == '\t') nick++;
 
 	if (*nick == '\0') {
-		strcpy(TRET, "c_hush: can't hush a null nickname");
+		strcpy(Tcl_GetStringResult(interp), "c_hush: can't hush a null nickname");
 		return(-1);
 	}
 
@@ -31,7 +31,7 @@
 		*(nick + MAX_NICKLEN) = '\0';
 
 	if ((hp = strmakenode(strlen(nick))) == NULL) {
-		strcpy(TRET, "c_hush: out of memory");
+		strcpy(Tcl_GetStringResult(interp), "c_hush: out of memory");
 		return(-1);
 	}
 	strcpy(hp->str, nick);
@@ -55,7 +55,7 @@
 	STRLIST *s;
 
 	if ((s = strgetnode(nick, hushhead, 1)) == NULL) {
-		sprintf(TRET, "c_hush: %s is not being hushed", nick);
+		sprintf(Tcl_GetStringResult(interp), "c_hush: %s is not being hushed", nick);
 		return(-1);
 	}
 	sprintf(mbuf, 
