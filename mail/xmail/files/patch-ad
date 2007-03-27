--- callMail.c.orig	Thu Jan 26 21:52:01 1995
+++ callMail.c	Wed Feb  4 23:30:07 1998
@@ -38,11 +38,10 @@
 #include	<sys/select.h>
 #endif
 
-#if	!(defined(SYSV) || defined(linux)) || defined(clipper)
+#if	!(defined(SYSV) || defined(linux) || defined(__FreeBSD__)) || defined(clipper)
 #include	<sgtty.h>
 #else
-#include	<sys/termio.h>
-#include	<sys/sysmacros.h>
+#include	<sys/termios.h>
 #include	<fcntl.h>
 #if	defined(att)
 #include	<sys/stropts.h>
@@ -81,7 +80,7 @@
 #ifdef		hpux
 #define	PTYCHAR2	"fedcba9876543210"
 #else	/* !hpux */
-#define	PTYCHAR2	"0123456789abcdef"
+#define	PTYCHAR2	"0123456789abcdefghijklmnopqrstuvwxyz"
 #endif	/* !hpux */
 #endif	/* !PTYCHAR2 */
 
@@ -207,8 +206,8 @@
 callMail(argv)
 char *argv[];
 {
-#if defined(linux) || (defined(SYSV)  && !defined(clipper))
- struct termio	tio;
+#if defined(linux) || defined(__FreeBSD__) || (defined(SYSV) && !defined(clipper))
+ struct termios	tio;
 #else	
  struct sgttyb	Sgtty;
 #endif
@@ -223,14 +222,14 @@
 /*
 ** Set minimal requirements for slave connection (no echo, no NL->CR, keep TABS)
 */
-#if defined(linux) || (defined(SYSV) && !defined(clipper))
- (void) ioctl(slave, TCGETA, &tio);
- tio.c_oflag &= ~(OCRNL|ONLCR|ONLRET|TABDLY);
+#if defined(linux) || defined(__FreeBSD__) || (defined(SYSV) && !defined(clipper))
+ tcgetattr(slave, &tio);
+ tio.c_oflag &= ~(OCRNL|ONLCR|ONLRET|OXTABS);
  tio.c_iflag &= ~IXOFF;
  tio.c_iflag |= ICRNL;
  tio.c_lflag &= ~(ISIG|ECHO);
  tio.c_lflag |= ICANON;
- (void) ioctl(slave, TCSETA, &tio);
+ tcsetattr(slave, TCSANOW, &tio);
 #else	
  (void) ioctl(slave, TIOCGETP, &Sgtty);
  Sgtty.sg_flags &= ~(ECHO|CRMOD|XTABS);
