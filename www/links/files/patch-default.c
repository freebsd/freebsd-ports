--- default.c.orig	Tue Feb 11 21:54:38 2003
+++ default.c	Sat Mar  1 16:03:31 2003
@@ -300,7 +300,7 @@
 	get_system_name();
 	links_home = get_home(&first_use);
 	if (!links_home) {
-		fprintf(stderr, "Unable to find or create links config directory. Please check, that you have $HOME variable set correctly and that you have write permission to your home directory.\n\007");
+		fprintf(stderr, "Unable to find or create links config directory. Please check, that you have set the $HOME variable correctly and that you have write permission to your home directory.\n");
 		sleep(3);
 		return;
 	}
