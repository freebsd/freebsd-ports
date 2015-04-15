--- src/subtitles.c.orig	2011-09-15 20:20:46 UTC
+++ src/subtitles.c
@@ -284,7 +284,7 @@ static char *convert_subtitle_to_utf8(co
       return NULL;
     }
     outptr=newtext;
-    if (iconv(cd, &inptr, &insz, &outptr, &outsz) < 0) {
+    if (iconv(cd, &inptr, &insz, &outptr, &outsz) == (size_t)-1) {
       warn(frontend, NULL, 0, "Failed to convert text to UTF-8\n");
       free(newtext);
       newtext = NULL;
