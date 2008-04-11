--- default.c.orig	2008-03-06 22:43:25.117856165 -0500
+++ default.c	2008-03-06 22:44:12.412560939 -0500
@@ -400,7 +400,7 @@
 	get_system_name();
 	links_home = get_home(&first_use);
 	if (!links_home) {
-		fprintf(stderr, "Unable to find or create links config directory. Please check, that you have $HOME variable set correctly and that you have write permission to your home directory.\n\007");
+		fprintf(stderr, "Unable to find or create links config directory. Please check, that you have $HOME variable set correctly and that you have write permission to your home directory.\n");
 		sleep(3);
 		return;
 	}
