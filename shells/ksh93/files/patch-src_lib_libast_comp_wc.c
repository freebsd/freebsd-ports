
$FreeBSD$

--- src/lib/libast/comp/wc.c.orig	Mon Oct  8 03:21:02 2001
+++ src/lib/libast/comp/wc.c	Mon Oct  8 03:21:20 2001
@@ -63,7 +63,6 @@
 wcrtomb(char* s, wchar_t c, mbstate_t* q)
 {
 #if _lib_wctomb
-	*q = 0;
 	memset(q, 0, sizeof(*q));
 	return wctomb(s, c);
 #else
