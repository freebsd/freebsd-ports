--- mkCTM/mkctm.c.ORI	2023-12-29 08:47:22.656993000 +0100
+++ mkCTM/mkctm.c	2023-12-29 08:48:29.101390000 +0100
@@ -32,6 +32,7 @@
 #include <err.h>
 #include <paths.h>
 #include <signal.h>
+#include <limits.h>
 
 #define DEFAULT_IGNORE	"/CVS$|/\\.#|00_TRANS\\.TBL$"
 #define DEFAULT_BOGUS	"\\.core$|\\.orig$|\\.rej$|\\.o$"
@@ -41,6 +42,7 @@
 int	verbose;
 int	damage, damage_limit;
 int	change;
+int	Have_ctm_status, Have_svn_revision;
 
 FILE	*logfile;
 
@@ -138,6 +140,10 @@
 	if (verbose > 1) {
 		fprintf(stderr, "%s %s%s\n", pfx, name, de->d_name);
 	}
+	if( strcmp( de->d_name, ".ctm_status" ) == 0 )
+	  Have_ctm_status = 1;
+	if( strcmp( de->d_name, ".svn_revision" ) == 0 )
+	  Have_svn_revision = 1;
 }
 
 void
@@ -769,7 +839,7 @@
 		errx(1, "damage of %d would exceed %d files", 
 			damage, damage_limit);
 /* change <= 2 means no change because of .ctm_status and .svn_revision */
-	} else if (change < 3) {
+	} else if (change < 1 + Have_ctm_status + Have_svn_revision ) {
 		errx(4, "no changes");
 	} else {
 		printf("CTM_END ");
