--- src/stdlib/icvt.c.orig	2006-04-08 02:50:46 UTC
+++ src/stdlib/icvt.c
@@ -84,7 +84,7 @@ iconv_trans (CNSTRING src, CNSTRING dest
 		/* assume MS-Windows makenarrow call */
 		inlen = 2 * wcslen((const wchar_t *)sin);
 	}
-	if (!strncmp(src, "UCS-2", strlen("UCS-2"))) {
+	if (!strncmp(src, "UCS-4", strlen("UCS-4"))) {
 		/* assume UNIX makenarrow call */
 		inlen = 4 * wcslen((const wchar_t *)sin);
 	}
