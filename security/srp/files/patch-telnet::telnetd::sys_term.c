--- telnet/telnetd/sys_term.c.orig	Tue Aug 21 09:02:37 2001
+++ telnet/telnetd/sys_term.c	Tue Aug 21 09:03:33 2001
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
