--- config.c.orig	Sun May  4 06:48:04 2003
+++ config.c	Sat Feb 19 11:30:53 2005
@@ -238,8 +238,8 @@
 	fprintf(makefile, "\nclean: \n\trm -f *.o core \n");
 	fprintf(makefile, "\ndistclean: clean\n\trm -f splitvt Makefile\n");
 	fprintf(makefile, "\ninstall: install-man\n");
-	fprintf(makefile, "\tmv splitvt /usr/local/bin/splitvt\n");
-	fprintf(makefile, "\tmv examples/xsplitvt /usr/local/bin/xsplitvt\n");
+	fprintf(makefile, "\tmv splitvt %%PREFIX%%/bin/splitvt\n");
+	fprintf(makefile, "\tmv examples/xsplitvt %%PREFIX%%/bin/xsplitvt\n");
 	fprintf(makefile, "\ninstall-man:\n");
 	fprintf(makefile, "\tcp splitvt.man /usr/local/man/man1/splitvt.1\n");
 
