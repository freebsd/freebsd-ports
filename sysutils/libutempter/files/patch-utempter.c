--- utempter.c.orig	Wed Aug 18 15:04:15 2004
+++ utempter.c	Wed Aug 18 15:16:18 2004
@@ -29,11 +29,11 @@
 #include <string.h>
 #include <unistd.h>
 #include <fcntl.h>
-#include <pty.h>
 #include <pwd.h>
 #include <sys/ioctl.h>
 #include <sys/stat.h>
 #include <utmp.h>
+#include <libutil.h>
 
 #define	DEV_PREFIX	"/dev/"
 #define	DEV_PREFIX_LEN	(sizeof(DEV_PREFIX)-1)
@@ -102,42 +102,29 @@
 		    pid_t pid, int add)
 {
 	struct utmp ut;
-	int     offset = strlen (term) - sizeof (ut.ut_id);
 
 	memset (&ut, 0, sizeof (ut));
 
-	strncpy (ut.ut_user, user, sizeof (ut.ut_user));
+	strncpy (ut.ut_name, user, sizeof (ut.ut_name));
 
 	strncpy (ut.ut_line, term, sizeof (ut.ut_line));
 
-	if (offset < 0)
-		offset = 0;
-	strncpy (ut.ut_id, term + offset, sizeof (ut.ut_id));
-
 	if (host)
 		strncpy (ut.ut_host, host, sizeof (ut.ut_host));
 
-	if (add)
-		ut.ut_type = USER_PROCESS;
-	else
-		ut.ut_type = DEAD_PROCESS;
-
-	ut.ut_pid = pid;
-
-	gettimeofday (&ut.ut_tv, 0);
+	time (&ut.ut_time);
 
-	setutent ();
-	if (!pututline (&ut))
-	{
+	if (add) {
+		login (&ut);
+	} else {
+		if (logout (term) != 1) {
 #ifdef	UTEMPTER_DEBUG
-		fprintf (stderr, "utempter: pututline: %s\n",
-			 strerror (errno));
+	fprintf (stderr, "utempter: logout: %s\n",
+		strerror (errno));
 #endif
 		exit (EXIT_FAILURE);
+		}
 	}
-	endutent ();
-
-	updwtmp (_PATH_WTMP, &ut);
 
 #ifdef	UTEMPTER_DEBUG
 	fprintf (stderr,
@@ -203,7 +190,7 @@
 		exit (EXIT_FAILURE);
 	}
 
-	device = ptsname (STDIN_FILENO);
+	device = ttyname (STDIN_FILENO);
 	if (!device)
 	{
 #ifdef	UTEMPTER_DEBUG
