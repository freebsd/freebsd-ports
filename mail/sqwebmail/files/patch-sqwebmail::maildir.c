--- sqwebmail/maildir.c.orig	Fri May 28 21:22:37 2004
+++ sqwebmail/maildir.c	Fri May 28 21:23:00 2004
@@ -1488,8 +1488,8 @@
 	as=rfc2047_decode_unicode(a, &unicode_UTF8, 0);
 	bs=rfc2047_decode_unicode(b, &unicode_UTF8, 0);
 #else
-	as=rfc2047_decode_simple(a, &unicode_UTF8);
-	bs=rfc2047_decode_simple(b, &unicode_UTF8);
+	as=rfc2047_decode_simple(a);
+	bs=rfc2047_decode_simple(b);
 #endif
 
 	if (as)
