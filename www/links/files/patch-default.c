--- default.c.orig	Sun Dec 31 14:26:52 2000
+++ default.c	Tue Mar 20 09:32:18 2001
@@ -265,7 +265,7 @@
 	get_system_name();
 	links_home = get_home(&first_use);
 	if (!links_home) {
-		fprintf(stderr, "Unable to find or create links config directory. Please check, that you have $HOME variable set correctly and that you have write permission to your home directory.\n\007");
+		fprintf(stderr, "Unable to find or create links config directory. Please check, that you have $HOME variable set correctly and that you have write permission to your home directory.\n");
 		sleep(3);
 		return;
 	}
