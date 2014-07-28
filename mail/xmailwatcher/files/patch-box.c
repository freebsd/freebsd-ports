--- box.c.orig	Sat Feb  3 18:13:00 2001
+++ box.c	Sat Feb  3 18:13:50 2001
@@ -31,7 +31,7 @@
 #include <unistd.h>
 #include <sys/stat.h>
 #include <sys/types.h>
-#include <sys/dir.h>
+#include <dirent.h>
 #include <X11/Xos.h>
 
 /* MIME processing */
@@ -235,7 +235,7 @@
 	int n, i, tally;
 	char oneFrom[160];
 	char *pos;
-	char filename[PATH_MAX];
+	char filename[FILENAME_MAX];
 
 	if (flags & BOX_DEBUG) (void) printf("MHparseMailbox(%s)\n", mailbox);
 
