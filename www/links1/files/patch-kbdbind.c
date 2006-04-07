--- kbdbind.c.orig	Wed Mar 20 09:22:48 2002
+++ kbdbind.c	Fri Apr  7 19:25:20 2006
@@ -74,7 +74,7 @@
 	long num;
 };
 
-static long strtonum(struct strtonum *table, char *s)
+static long mystrtonum(struct strtonum *table, char *s)
 {
 	struct strtonum *p;
 	for (p = table; p->str; p++) 
@@ -90,7 +90,7 @@
 		{ "menu", KM_MENU },
 		{ NULL, 0 }
 	};
-	return strtonum(table, s);
+	return mystrtonum(table, s);
 }
 
 static long parse_key(unsigned char *s)
@@ -124,7 +124,7 @@
 		{ "F12", KBD_F12 },
 		{ NULL, 0 }
 	};
-	return (strlen(s) == 1) ? *s : strtonum(table, s);
+	return (strlen(s) == 1) ? *s : mystrtonum(table, s);
 }
 
 static int parse_keystroke(unsigned char *s, long *x, long *y)
