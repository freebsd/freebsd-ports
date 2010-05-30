diff -ur ../old/FD-3.00f/string.c ./string.c
--- ../old/FD-3.00f/string.c	Sat May 29 00:00:00 2010
+++ ./string.c	Sat May 29 19:52:52 2010
@@ -43,7 +43,10 @@
 {
 	for (; n-- > 0; s++) {
 		if (*s == c) return((char *)s);
-		else if (iswchar(s, 0)) s++;
+		else if (iswchar(s, 0)) {
+			if (n-- <= 0) break;
+			s++;
+		}
 	}
 
 	return(NULL);
