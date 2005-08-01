--- lib/files.c.orig	Tue May 17 01:42:34 2005
+++ lib/files.c	Fri Jul 29 21:26:37 2005
@@ -45,7 +45,8 @@
 bool synce_get_directory(char** path)
 {
 	char buffer[MAX_PATH];
-    char *p;
+	char *p;
+	struct passwd* user;
 
 	/* if there is a preference for config dir set
 	   as an environment variable, use it */
@@ -57,7 +58,7 @@
 	}
 	
 	/* XXX: not very thread-safe? */
-	struct passwd* user = getpwuid(getuid());
+	user = getpwuid(getuid());
 
 	if (!path)
 		return false;
