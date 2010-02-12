--- do_acct.c.orig	2010-01-23 16:17:36.000000000 -0500
+++ do_acct.c	2010-02-12 18:19:44.000000000 -0500
@@ -202,23 +202,42 @@ do_acct_syslog(struct acct_rec *rec)
 int
 wtmp_entry(char *line, char *name, char *host, time_t utime)
 {
+#if defined(FREEBSD) && __FreeBSD_version >= 900007
+#define HAVE_UTMPX_H 1
+    struct utmpx entry;
+    struct timeval tv;
+#else
     struct utmp entry;
+#endif
 
+#ifndef HAVE_UTMPX_H
     if (!wtmpfile) {
 	return(1);
     }
+#endif
 
     memset(&entry, 0, sizeof entry);
+#ifdef HAVE_UTMPX_H
+    entry.ut_type = *name != '\0' ? USER_PROCESS : DEAD_PROCESS;
+    snprintf(entry.ut_id, sizeof entry.ut_id, "%xtac", getpid());
+#endif
 
     if (strlen(line) < sizeof entry.ut_line)
 	strcpy(entry.ut_line, line);
     else
 	memcpy(entry.ut_line, line, sizeof(entry.ut_line));
 
+#ifdef HAVE_UTMPX_H
+    if (strlen(name) < sizeof entry.ut_user)
+	strcpy(entry.ut_user, name);
+    else
+	memcpy(entry.ut_user, name, sizeof(entry.ut_user));
+#else
     if (strlen(name) < sizeof entry.ut_name)
 	strcpy(entry.ut_name, name);
     else
 	memcpy(entry.ut_name, name, sizeof(entry.ut_name));
+#endif
 
 #ifndef SOLARIS
     if (strlen(host) < sizeof entry.ut_host)
@@ -226,13 +245,24 @@ wtmp_entry(char *line, char *name, char 
     else
 	memcpy(entry.ut_host, host, sizeof(entry.ut_host));
 #endif
+#ifdef HAVE_UTMPX_H
+    memset(&entry.ut_tv, 0, sizeof(entry.ut_tv));
+    tv.tv_sec = utime;
+    memcpy(&entry.ut_tv, &tv, sizeof(entry.ut_tv));
+#else
     entry.ut_time = utime;
+#endif
 
 #ifdef FREEBSD
+#ifdef HAVE_UTMPX_H
+    pututxline(&entry);
+#else
     wtmpfd = open(wtmpfile, O_CREAT | O_WRONLY | O_APPEND, 0644);
+#endif
 #else
     wtmpfd = open(wtmpfile, O_CREAT | O_WRONLY | O_APPEND | O_SYNC, 0644);
 #endif
+#ifndef HAVE_UTMPX_H
     if (wtmpfd < 0) {
 	report(LOG_ERR, "Can't open wtmp file %s -- %s",
 	       wtmpfile, strerror(errno));
@@ -251,6 +281,7 @@ wtmp_entry(char *line, char *name, char 
     }
 
     close(wtmpfd);
+#endif
 
     if (debug & DEBUG_ACCT_FLAG) {
 	report(LOG_DEBUG, "wtmp: %s, %s %s %d", line, name, host, utime);
