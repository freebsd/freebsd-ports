--- src/siggen.c.orig	Tue Jun 13 23:42:53 2000
+++ src/siggen.c	Tue Jun 13 23:43:27 2000
@@ -52,7 +52,6 @@
 
 extern int optind;
 int debuglevel = 0;
-char *mktemp();
 
 int (*pf_signatures [NUM_SIGS]) () = {
 					SIG0FUNC,
@@ -172,8 +171,8 @@
 	};
 	(void) strcpy(tmpfilename, "/tmp/twzXXXXXX");
 
-	if ((char *) mktemp(tmpfilename) == NULL) {
-	    perror("siggen: mktemp()");
+	if (mkstemp(tmpfilename) == -1) {
+	    perror("siggen: mkstemp()");
 	    exit(1);
 	}
 
