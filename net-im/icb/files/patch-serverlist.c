$NetBSD: patch-ai,v 1.2 1999/11/26 22:12:37 hubertf Exp $

diff -x *.orig -urN ./icb/serverlist.c /usr/pkgsrc/net/icb/work.i386.unpatched/icb-5.0.9/icb/serverlist.c
--- ./icb/serverlist.c	Fri Feb 24 22:20:29 1995
+++ /usr/pkgsrc/net/icb/work.i386.unpatched/icb-5.0.9/icb/serverlist.c	Fri Nov 26 22:56:29 1999
@@ -1,4 +1,6 @@
 #include <stdio.h>
+#include <stdlib.h>
+#include <pwd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include "icb.h"
@@ -14,15 +16,14 @@
 FILE *openserverfile()
 {
 	struct stat statbuf;
-	char *personalsl;
-	char command[256];
-	char pwd[256];
+	char *personalsl, *home;
+	char pwd[MAXPATHLEN+1];
 	FILE *ret;
 
 #ifdef sgi
 #undef SYSV
 #endif
-#ifndef SYSV
+#if !defined(SYSV) && !(defined(BSD) && BSD >= 199306) && !defined(__linux__)
 	getwd(pwd);
 #else /* SYSV */
 	getcwd(pwd, MAXPATHLEN+1);
@@ -30,11 +31,20 @@
 #ifdef sgi
 #define SYSV
 #endif
-	chdir(getenv("HOME"));
+	if ((home = getenv("HOME")) == NULL) {
+		struct passwd *pw;
+		if ((pw = getpwuid(getuid())) == NULL)
+			home = ".";
+		home = pw->pw_dir;
+	}
+	chdir(home);
 	if (!stat(PERSONALSL,&statbuf))
 	{
-		sprintf(command,"/bin/cat %s %s\n", PERSONALSL, SERVERLIST);
+		char *command = malloc(strlen("/bin/cat  \n") +
+			strlen(PERSONALSL) + strlen(SERVERLIST) + 1);
+		sprintf(command, "/bin/cat %s %s\n", PERSONALSL, SERVERLIST);
 		ret= popen(command,"r");
+		free(command);
 	}
 	else
 		ret= fopen(SERVERLIST,"r");
