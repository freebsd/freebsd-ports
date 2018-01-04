--- slushd.c.orig	1999-05-07 02:24:09 UTC
+++ slushd.c
@@ -40,11 +40,19 @@
 #include <ctype.h>
 #include <stdlib.h>
 #include <netdb.h>
+#include <sys/param.h>
+#if __FreeBSD_version >= 500000
 #include <getopt.h>
+#endif
 #include <pwd.h>
 #include <grp.h>
 #include <fcntl.h>
+#if __FreeBSD_version >= 900007
+#include <utmpx.h>
+#else
 #include <utmp.h>
+#include <libutil.h>
+#endif
 #include <limits.h>
 #include <paths.h>
 #include <sys/types.h>
@@ -653,59 +661,42 @@ int process_control_word(const char *tok
 /* exits on error */
 void log_uwtmp(struct passwd *pw, struct in_addr *i, char *tty, int is_logout)
 {
-	struct utmp ut;
-	int wtmp;
-	int lock;
-	
-	tty = strrchr(tty, '/');
-	if (tty == NULL)
-	{
-		syslog(LOG_ERR, "Can't determine basename of tty");
-		exit(3);
-	}
-	tty++;
-	
-	utmpname(_PATH_UTMP);
-	setutent();
-	memset(&ut, 0, sizeof(ut));
+#if __FreeBSD_version >= 900007
+	struct utmpx ut;
 
-	if (ut.ut_id[0] == 0)
-		strncpy(ut.ut_id, tty + 3, sizeof(ut.ut_id));
+	if (strncmp(tty, "/dev/", 5) == 0)
+		tty += 5;
 
-	if (!is_logout)
-		strncpy(ut.ut_user, pw->pw_name, sizeof(ut.ut_user));
-	
-	strncpy(ut.ut_line, tty, sizeof(ut.ut_line) - 1);
-	ut.ut_line[sizeof(ut.ut_line) - 1] = 0;
-	
-	ut.ut_time = time(NULL);
-	ut.ut_type = is_logout?DEAD_PROCESS:USER_PROCESS;
-	ut.ut_pid = getpid();
+	memset(&ut, 0, sizeof ut);
+	gettimeofday(&ut.ut_tv, NULL);
+	strncpy(ut.ut_id, tty, sizeof ut.ut_id);
 
-	strncpy(ut.ut_host, hostname, sizeof(ut.ut_host) - 1);
-	ut.ut_host[sizeof(ut.ut_host) - 1] = 0;
-	
-	memcpy(&ut.ut_addr, i, sizeof(ut.ut_addr));
+	if (is_logout) {
+		ut.ut_type = DEAD_PROCESS;
+	} else {
+		ut.ut_type = USER_PROCESS;
+		strncpy(ut.ut_line, tty, sizeof ut.ut_line);
+		strncpy(ut.ut_user, pw->pw_name, sizeof ut.ut_user);
+		strncpy(ut.ut_host, inet_ntoa(*i), sizeof ut.ut_host);
+	}
+	pututxline(&ut);
+#else
+	struct utmp ut;
 
-	pututline(&ut);
-	endutent();
+	if (strncmp(tty, "/dev/", 5) == 0)
+		tty += 5;
 
-	lock = open(_PATH_WTMPLOCK, O_CREAT|O_WRONLY, 0660);
-	if (lock == -1)
-		ioerror("open");
-		
-	if (flock(lock, LOCK_EX) == -1)
-		ioerror("flock");
-		
-	wtmp = open(_PATH_WTMP, O_APPEND|O_WRONLY);
-	if (wtmp == -1)
-		ioerror("open");
-		
-	write(wtmp, (char *)&ut, sizeof(ut));
-	close(wtmp);
+	if (is_logout) {
+		logout(tty);
+		return;
+	}
 
-	flock(lock, LOCK_UN);
-	close(lock);
+	strncpy(ut.ut_line, tty, sizeof ut.ut_line);
+	strncpy(ut.ut_name, pw->pw_name, sizeof ut.ut_name);
+	strncpy(ut.ut_host, inet_ntoa(*i), sizeof ut.ut_host);
+	ut.ut_time = time(0);
+	login(&ut);
+#endif
 }
 
 /* Retrieve client X509 certificate and test authentication */
