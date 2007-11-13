--- libyahoo/libyahoo.c.orig	2007-11-12 15:12:19.000000000 +0100
+++ libyahoo/libyahoo.c	2007-11-12 15:13:33.000000000 +0100
@@ -746,15 +746,15 @@
 static char *yahoo_urlencode(const char *instr)
 {
 	register int ipos, bpos;	//input str pos., buffer pos.
-	static unsigned char *str = NULL;
+	static char *str = NULL;
 	int len = strlen(instr);
 	int tmp;
 
 	//attempt to reuse buffer
 	if (NULL == str)
-		str = (unsigned char *) malloc(3 * len + 1);
+		str = malloc(3 * len + 1);
 	else
-		str = (unsigned char *) realloc(str, 3 * len + 1);
+		str = realloc(str, 3 * len + 1);
 
 	//malloc, realloc failed ?
 	if (errno == ENOMEM)
@@ -791,7 +791,7 @@
 
 	//free extra alloc'ed mem.
 	tmp = strlen(str);
-	str = (unsigned char *) realloc(str, tmp + 1);
+	str = realloc(str, tmp + 1);
 
 	return (str);
 }
