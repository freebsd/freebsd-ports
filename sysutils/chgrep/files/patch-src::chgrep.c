--- src/chgrep.c.orig	Sun Apr 20 22:58:09 2003
+++ src/chgrep.c	Sun Apr 20 22:58:18 2003
@@ -132,11 +132,6 @@
 		file_quit = NULL;
 		tmpfile_quit = NULL;
 
-		if (recursive) {
-			ftw(argv[opttmp], list, sysconf(_SC_OPEN_MAX));
-			return 0;
-		}
-
 		if ( ! istmpfilename) {	/* if we don't use -t filename.tmp */
 			strcat(strcpy(tmpfile, argv[opttmp]), ".lock");
 			if ( (fdout = open(tmpfile, O_RDONLY, PERM)) != -1) {
