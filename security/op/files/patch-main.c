--- main.c.orig	Tue Sep  9 01:24:31 2003
+++ main.c	Tue Sep  9 01:29:26 2003
@@ -448,29 +448,17 @@
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
 		;		/* don't have a default */
 	} else {
 		for (cp=GetField(cp, str); cp!=NULL; cp=GetField(cp, str)) {
-			if ((gr = getgrnam(cp)) != NULL)
+			if ((gr = getgrnam(str)) != NULL)
 				gidset[ngroups++] = gr->gr_gid;
 		}
 		if (ngroups == 0) 
@@ -533,6 +521,18 @@
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
+		}
+		if (setuid(pw->pw_uid) < 0)
+			fatal("Unable to set uid to %s", cp);
+	}
 
 	if (strcmp("MAGIC_SHELL", cmd->args[0]) == 0) {
 		for (i = 0; environ[i] != NULL; i++) 
