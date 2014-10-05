--- popt/popthelp.c.orig	2004-08-25 15:06:39 UTC
+++ popt/popthelp.c
@@ -683,7 +683,7 @@
     s[0] = '\0';
     /*@-branchstate@*/		/* FIX: W2DO? */
     if (str == NULL) {
-	memset(s, 0, sizeof(s));
+	memset(s, 0, 300);
 	str = s;
     }
     /*@=branchstate@*/
