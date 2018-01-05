--- default.c.orig	2016-11-16 22:49:10 UTC
+++ default.c
@@ -836,7 +836,7 @@ void init_home(void)
 	get_compiler_name();
 	links_home = get_home(&first_use);
 	if (!links_home) {
-		fprintf(stderr, "Unable to find or create links config directory. Please check, that you have $HOME variable set correctly and that you have write permission to your home directory.\n\007");
+		fprintf(stderr, "Unable to find or create links config directory. Please check, that you have $HOME variable set correctly and that you have write permission to your home directory.\n");
 		portable_sleep(3000);
 		return;
 	}
