--- ldecod/src/ldecod.c.orig	2020-09-29 10:22:20 UTC
+++ ldecod/src/ldecod.c
@@ -77,7 +77,7 @@
 // Decoder definition. This should be the only global variable in the entire
 // software. Global variables should be avoided.
 DecoderParams  *p_Dec;
-char errortext[ET_SIZE];
+extern char errortext[ET_SIZE];
 
 // Prototypes of static functions
 static void Report      (VideoParameters *p_Vid);
