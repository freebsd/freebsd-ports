--- utils/idna.c.orig	2020-05-24 20:55:29 UTC
+++ utils/idna.c
@@ -167,7 +167,7 @@ idna__ace_to_ucs4(const char *ace_label,
 
 #ifdef WITH_UTF8PROC
 
-#include <libutf8proc/utf8proc.h>
+#include <utf8proc.h>
 
 int32_t idna_contexto[] = {
 	/* CONTEXTO codepoints which have a rule defined */
