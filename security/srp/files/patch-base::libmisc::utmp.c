--- base/libmisc/utmp.c.orig	Tue Aug 21 09:00:37 2001
+++ base/libmisc/utmp.c	Tue Aug 21 09:01:33 2001
@@ -371,6 +371,9 @@
 	int	found = 0;
 	off_t	pos;
 
+#if defined(__FreeBSD__)
+#define _UTMP_FILE _PATH_UTMP
+#endif
 	if ((fd = open(_UTMP_FILE, O_RDWR)) < 0)
 		return;
 
