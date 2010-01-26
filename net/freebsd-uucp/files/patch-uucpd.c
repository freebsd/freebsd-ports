--- uucpd/uucpd.c.orig	2007-09-10 10:57:58.000000000 +0200
+++ uucpd/uucpd.c	2010-01-26 22:03:02.000000000 +0100
@@ -73,7 +73,11 @@
 #include <syslog.h>
 #include <time.h>
 #include <unistd.h>
+#if __FreeBSD_version >= 900007
+#include <utmpx.h>
+#else
 #include <utmp.h>
+#endif
 #include <libutil.h>
 
 #include "pathnames.h"
@@ -110,11 +114,13 @@
 
 #endif /* USE_PAM */
 
+#if __FreeBSD_version < 900007
 #if (MAXLOGNAME-1) > UT_NAMESIZE
 #define LOGNAMESIZE UT_NAMESIZE
 #else
 #define LOGNAMESIZE (MAXLOGNAME-1)
 #endif
+#endif
 
 #define	SCPYN(a, b)	strncpy(a, b, sizeof (a))
 
@@ -196,7 +202,11 @@
 	} while (user[0] == '\0');
 
 	/* truncate username to LOGNAMESIZE characters */
+#if __FreeBSD_version >= 900007
+	user[sizeof user - 1] = '\0';
+#else
 	user[LOGNAMESIZE] = '\0';
+#endif
 
 	/* always ask for passwords to deter account guessing */
 	printf("Password: "); fflush(stdout);
@@ -468,11 +478,24 @@
 {
 	int status;
 	pid_t pid;
+#if __FreeBSD_version >= 900007
+	struct utmpx ut;
+#else
 	char line[32];
+#endif
 
 	while ((pid=wait((int *)&status)) > 0) {
+#if __FreeBSD_version >= 900007
+		memset(&ut, 0, sizeof ut);
+		ut.ut_type = DEAD_PROCESS;
+		gettimeofday(&ut.ut_tv, NULL);
+		ut.ut_pid = pid;
+		snprintf(ut.ut_id, sizeof ut.ut_id, "%xuucp", pid);
+		pututxline(&ut);
+#else
 		sprintf(line, "uucp%ld", (long)pid);
 		logwtmp(line, "", "");
+#endif
 	}
 }
 
@@ -481,6 +504,18 @@
  */
 void dologin(struct passwd *pw, struct sockaddr *sin)
 {
+#if __FreeBSD_version >= 900007
+	struct utmpx ut;
+
+	memset(&ut, 0, sizeof ut);
+	ut.ut_type = USER_PROCESS;
+	gettimeofday(&ut.ut_tv, NULL);
+	ut.ut_pid = getpid();
+	snprintf(ut.ut_id, sizeof ut.ut_id, "%xuucp", ut.ut_pid);
+	SCPYN(ut.ut_user, pw->pw_name);
+	realhostname_sa(ut.ut_host, sizeof ut.ut_host, sin, sin->sa_len);
+	pututxline(&ut);
+#else
 	char line[32];
 	char remotehost[UT_HOSTSIZE + 1];
 	int f;
@@ -503,4 +539,5 @@
 		(void) close(f);
 	}
 	logwtmp(line, pw->pw_name, remotehost);
+#endif
 }
