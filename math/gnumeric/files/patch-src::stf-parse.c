--- src/stf-parse.c.orig	Fri Mar  1 21:03:09 2002
+++ src/stf-parse.c	Fri Mar  1 21:03:17 2002
@@ -870,8 +870,7 @@
 		if (len == -1)
 			return (char *)s;
 		if (len > 1) {
-			if (mbstowcs (&wstr, s, 1) == 1 &&
-			    !iswprint (wstr) && !iswspace (wstr))
+			if (mbstowcs (&wstr, s, 1) == 1)
 				return (char *)s;
 			s += len;
 		} else {
