
$FreeBSD$

--- src/stf-parse.c	2001/12/27 19:36:17	1.1
+++ src/stf-parse.c	2001/12/27 19:44:24
@@ -29,8 +29,6 @@
 #include "clipboard.h"
 
 #include <ctype.h>
-#include <wctype.h>
-#include <stdlib.h>
 
 #define WARN_TOO_MANY_ROWS _("Too many rows in data to parse: %d")
 #define WARN_TOO_MANY_COLS _("Too many columns in data to parse: %d")
@@ -865,20 +863,9 @@
 	wchar_t wstr;
 	int len;
 
-	for (s = data; *s != '\0';) {
-		len = mblen(s, MB_CUR_MAX);
-		if (len == -1)
+	for (s = data; *s != '\0'; s++) {
+		if (!isprint (*s) && !isspace (*s))
 			return (char *)s;
-		if (len > 1) {
-			if (mbstowcs (&wstr, s, 1) == 1 &&
-			    !iswprint (wstr) && !iswspace (wstr))
-				return (char *)s;
-			s += len;
-		} else {
-			if (!isprint (*s) && !isspace (*s))
-				return (char *)s;
-			s++;
-		}
 	}
 
 	return NULL;
