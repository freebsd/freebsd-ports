--- src/config.parse.c.orig	Tue Jun 13 23:24:14 2000
+++ src/config.parse.c	Tue Jun 13 23:30:35 2000
@@ -55,7 +55,6 @@
 #endif
 
 /* prototypes */
-char *mktemp();
 static void configfile_descend();
 
 #ifndef L_tmpnam
@@ -105,8 +104,8 @@
     };
     (void) strcpy(tmpfilename, TEMPFILE_TEMPLATE);
 
-    if ((char *) mktemp(tmpfilename) == NULL) {
-	perror("configfile_read: mktemp()");
+    if (mkstemp(tmpfilename) == -1) {
+	perror("configfile_read: mkstemp()");
 	exit(1);
     }
 
