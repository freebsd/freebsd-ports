--- config.c.orig	Sun Jan 14 11:33:17 2001
+++ config.c	Sun Jan 14 11:33:36 2001
@@ -237,8 +237,8 @@
 #endif
 	fprintf(makefile, "\nclean: \n\trm -f *.o core \n");
 	fprintf(makefile, "\ndistclean: clean\n\trm -f splitvt Makefile\n");
-	fprintf(makefile, "\ninstall: \n\tmv splitvt /usr/local/bin/splitvt\n");
-	fprintf(makefile, "\tmv examples/xsplitvt /usr/local/bin/xsplitvt\n");
+	fprintf(makefile, "\ninstall: \n\tmv splitvt %%PREFIX%%/bin/splitvt\n");
+	fprintf(makefile, "\tmv examples/xsplitvt %%PREFIX%%/bin/xsplitvt\n");
 
 	fclose(makefile);
 	exit(0);
