--- lib/support/plausible.c.orig	2020-01-06 23:10:17 UTC
+++ lib/support/plausible.c
@@ -62,7 +62,7 @@ static void *magic_handle;
 static int magic_library_available(void)
 {
 	if (!magic_handle) {
-		magic_handle = dlopen("libmagic.so.1", RTLD_NOW);
+		magic_handle = dlopen("libmagic.so", RTLD_NOW);
 		if (!magic_handle)
 			return 0;
 
