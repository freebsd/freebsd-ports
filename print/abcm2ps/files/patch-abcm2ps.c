--- abcm2ps.c.orig	2017-02-02 14:03:34 UTC
+++ abcm2ps.c
@@ -422,8 +422,7 @@ static void display_version(int full)
 	fputs("abcm2ps-" VERSION " (" VDATE ")\n", stderr);
 	if (!full)
 		return;
-	fputs("Compiled: " __DATE__ "\n"
-	       "Options:"
+	fputs("Options:"
 #ifdef A4_FORMAT
 		" A4_FORMAT"
 #endif
