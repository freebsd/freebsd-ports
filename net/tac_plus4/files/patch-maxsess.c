--- maxsess.c.orig	Tue Jul 18 13:53:34 2006
+++ maxsess.c	Sun Oct 29 02:52:16 2006
@@ -464,7 +464,11 @@ ckfinger(char *user, char *nas, struct i
 	}
 	/* Extract username, up to 10 chars wide, starting at char 13 */
 	nmlen = 0;
+#if (TAC_IOS_VERSION == 11)
 	name = p + 13;
+#else
+	name = p + 15;
+#endif
 	for (i = 0; *name && !isspace((int) *name) && (i < 10); i++) {
 	    nmbuf[nmlen++] = *name++;
 	}
