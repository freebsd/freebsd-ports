--- src/lib/libast/comp/wc.c.orig	Fri May  4 00:29:32 2001
+++ src/lib/libast/comp/wc.c	Fri Aug  3 19:04:19 2001
@@ -63,7 +63,7 @@
 wcrtomb(char* s, wchar_t c, mbstate_t* q)
 {
 #if _lib_wctomb
-	*q = 0;
+	bzero(q, sizeof(q));
 	return wctomb(s, c);
 #else
 	if (s)
