--- src/stf-parse.c.orig	Thu Sep 12 00:21:07 2002
+++ src/stf-parse.c	Thu Sep 12 00:21:59 2002
@@ -876,8 +876,7 @@
 		if (len == -1)
 			return (char *)s;
 		if (len > 1) {
-			if (mbstowcs (&wstr, s, 1) == 1 &&
-			    !iswprint (wstr) && !iswspace (wstr))
+			if (mbstowcs (&wstr, s, 1) == 1)
 				return (char *)s;
 			s += len;
 		} else
