--- default.c.orig	Sun May 19 20:12:20 2002
+++ default.c	Sun May 19 20:12:23 2002
@@ -267,7 +267,7 @@
 	get_system_name();
 	links_home = get_home(&first_use);
 	if (!links_home) {
-		fprintf(stderr, "Unable to find or create links config directory. Please check, that you have $HOME variable set correctly and that you have write permission to your home directory.\n\007");
+		fprintf(stderr, "Unable to find or create links config directory. Please check, that you have $HOME variable set correctly and that you have write permission to your home directory.\n");
 		sleep(3);
 		return;
 	}
