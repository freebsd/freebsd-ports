--- src/xdvshow-audio.c.orig	Mon May  6 23:22:38 2002
+++ src/xdvshow-audio.c	Mon May 12 22:38:09 2003
@@ -36,9 +36,9 @@
 #include <fcntl.h>
 #include <unistd.h>
 
-#ifdef	FREEBSD_4
+#ifdef	__FreeBSD__
 #include <sys/soundcard.h>
-#endif	/* FREEBSD_4 */
+#endif	/* __FreeBSD__ */
 
 #ifdef	NETBSD
 #include <sys/ioccom.h>
