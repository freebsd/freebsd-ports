--- telnet/telnetd/sys_term.c.orig	Tue Jul 31 01:27:05 2001
+++ telnet/telnetd/sys_term.c	Tue Jan 22 16:31:27 2002
@@ -111,6 +111,9 @@
 #  else
 char	wtmpf[]	= "/usr/adm/wtmp";
 #  endif
+#if defined(__FreeBSD__)
+#define UTMP_FILE _PATH_UTMP
+#endif
 #  ifdef UTMP_FILE
 char	utmpf[] = UTMP_FILE;
 #  else
@@ -1473,7 +1476,7 @@
 {
 	register int i;
 	int syncpipe[2];
-#if defined(OSF) || defined(ultrix) || defined(__hpux)
+#if defined(OSF) || defined(ultrix) || defined(__hpux) || defined(__FreeBSD__)
 	time_t time();
 #else
 	long time();
