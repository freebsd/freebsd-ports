--- callMail.c.orig	1995-01-26 21:52:01.000000000 -0800
+++ callMail.c	2023-07-18 07:01:24.570712000 -0700
@@ -34,15 +34,21 @@
 #include	<sys/stat.h>
 #include	<signal.h>
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <termios.h>
+#include <libutil.h>
+#endif
+
 #if	defined(AIXV3) || defined(_IBMR2)
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
@@ -81,7 +87,7 @@
 #ifdef		hpux
 #define	PTYCHAR2	"fedcba9876543210"
 #else	/* !hpux */
-#define	PTYCHAR2	"0123456789abcdef"
+#define	PTYCHAR2	"0123456789abcdefghijklmnopqrstuvwxyz"
 #endif	/* !hpux */
 #endif	/* !PTYCHAR2 */
 
@@ -91,6 +97,7 @@
 char		pseudo_tty[20];
 
 
+#ifndef __FreeBSD__
 /*
 ** @(#) openMaster - searches for and opens a pty master.  If it finds one,
 **		     it returns the value of the file descriptor.  If not,
@@ -197,6 +204,7 @@
 #endif
  return(-1);				/* look for more master/slave pairs */
 } /* openSlave */
+#endif /* __FreeBSD__ */
 
 
 /*
@@ -207,30 +215,34 @@
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
  int		slave;			/* file descriptor to slave pty */
 
 
+#ifdef __FreeBSD__
+ openpty(&mail_fd, &slave, NULL, NULL, NULL);
+#else
  for (;;) {				/* find a pair, or master fails */
      mail_fd = openMaster();
      if ((slave = openSlave(mail_fd)) != -1)
         break;
     }
+#endif
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
