--- main.c.orig	Mon Dec 22 23:26:47 2003
+++ main.c	Mon Dec 22 23:27:23 2003
@@ -9,7 +9,7 @@
 /* +-------------------------------------------------------------------+ */
 
 #include <stdio.h>
-#include <varargs.h>
+#include <stdarg.h>
 #include <syslog.h>
 #include <pwd.h>
 #include <grp.h>
@@ -51,6 +51,7 @@
 extern char	*getpass(), *crypt();
 
 char	*Progname;
+int	fatal(char *s, ...);
 char    *format_cmd();
 char    *GetCode();
 cmd_t	*Find();
@@ -170,14 +171,11 @@
 	return Go(new, num, argc, argv);
 }
 
-fatal(va_alist)
- va_dcl
+fatal(char *s,...)
 {
 	va_list	ap;
-	char	*s;
 
-	va_start(ap);
-	s = va_arg(ap, char *);
+	va_start(ap,s);
 	vfprintf(stderr, s, ap);
 	fputc('\n', stderr);
 	va_end(ap);
@@ -448,35 +446,28 @@
 	char		*cp, *np;
 	struct passwd	*pw;
 	struct group	*gr;
-	int		ngroups, gidset[256];
+	int		ngroups = 0, gidset[256];
 	int		curenv = 0, curarg = 0;
 	char		*new_envp[MAXENV];
 	char		*new_argv[MAXARG];
 	char		str[MAXSTRLEN], buf[4*MAXSTRLEN];
 
-	if ((cp = FindOpt(cmd, "uid")) == NULL) {
-		if (setuid(0) < 0)
-			fatal("Unable to set uid to default", cp);
-	} else {
-		if ((pw = getpwnam(cp)) == NULL) {
-			if (setuid(atoi(cp)) < 0)
-				fatal("Unable to set uid to %s", cp);
-		}
-		if (setuid(pw->pw_uid) < 0)
-			fatal("Unable to set uid to %s", cp);
-	}
-
 	if ((cp = FindOpt(cmd, "gid")) == NULL) {
-		;		/* don't have a default */
+		if (setgid(0) < 0)
+			fatal("Unable to set gid to default", cp);
 	} else {
 		for (cp=GetField(cp, str); cp!=NULL; cp=GetField(cp, str)) {
-			if ((gr = getgrnam(cp)) != NULL)
+			if ((gr = getgrnam(str)) != NULL)
 				gidset[ngroups++] = gr->gr_gid;
+			else
+				gidset[ngroups++] = atoi(str);
 		}
 		if (ngroups == 0) 
-			fatal("Unable to setgid to any group");
+			fatal("Unable to set gid to any group");
 		if (setgroups(ngroups, gidset) < 0)
-			fatal("Set group failed");
+			fatal("Unable to set auxiliary groups");
+		if (setgid(gidset[0]) < 0)
+			fatal("Unable to set gid to %s", gidset[0]);
 	}
 
 	if ((cp = FindOpt(cmd, "umask")) == NULL) {
@@ -533,6 +524,17 @@
 			new_envp[curenv++] = environ[i];
 	}
 	new_envp[curenv] = NULL;
+
+	if ((cp = FindOpt(cmd, "uid")) == NULL) {
+		if (setuid(0) < 0)
+			fatal("Unable to set uid to default", cp);
+	} else {
+		if ((pw = getpwnam(cp)) == NULL) {
+			if (setuid(atoi(cp)) < 0)
+				fatal("Unable to set uid to %s", cp);
+		} else if (setuid(pw->pw_uid) < 0)
+			fatal("Unable to set uid to %s", cp);
+	}
 
 	if (strcmp("MAGIC_SHELL", cmd->args[0]) == 0) {
 		for (i = 0; environ[i] != NULL; i++) 
