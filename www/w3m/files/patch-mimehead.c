--- mimehead.c.orig	Fri Mar 23 10:49:53 2001
+++ mimehead.c	Tue Jun 19 21:46:21 2001
@@ -166,21 +166,20 @@
 Str
 decodeWord(char **ow)
 {
-    char charset[32];
     char *p, *w = *ow;
     char method;
     Str a = Strnew();
+    Str charset = Strnew();
 
     if (*w != '=' || *(w + 1) != '?')
 	goto convert_fail;
     w += 2;
-    for (p = charset; *w != '?'; w++) {
+    for (; *w != '?'; w++) {
 	if (*w == '\0')
 	    goto convert_fail;
-	*(p++) = *w;
+	Strcat_char(charset,*w);
     }
-    *p = '\0';
-    if (strcasecmp(charset, J_CHARSET) != 0) {
+    if (Strcasecmp_charp(charset, J_CHARSET) != 0) {
 	/* NOT ISO-2022-JP encoding ... don't convert */
 	goto convert_fail;
     }
