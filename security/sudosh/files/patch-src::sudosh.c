--- src/sudosh.c.orig	Tue Oct 26 18:01:24 2004
+++ src/sudosh.c	Sat Nov 13 19:31:14 2004
@@ -24,6 +24,9 @@
 #include <unistd.h>
 #include <signal.h>
 #include <pwd.h>
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
 
 #include "config.h"
 
@@ -75,6 +78,12 @@
 #define SIGCHLD	SIGCLD
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <libutil.h>
+#endif
+
 static struct termios termorig;
 static struct winsize winorig;
 
@@ -99,6 +108,9 @@
 static void rawmode (int);
 static int findms (struct pst *);
 void mysyslog (int, const char *, ...);
+#ifdef __FreeBSD__
+static void sanemode(int ttyfd);
+#endif
 
 int
 main (int argc, char *argv[], char *environ[])
@@ -255,8 +267,9 @@
   mysyslog (LOG_INFO, start_msg);
   mysyslog (LOG_INFO, "to view this session type: sudosh-replay %s-%i",
 	    user, now);
-
+#ifndef __FreeBSD__
   rawmode (0);
+#endif
 
   if (findms (&pspair) < 0)
     {
@@ -269,6 +282,9 @@
     case 0:
       close (pspair.mfd);
       prepchild (&pspair);
+#ifdef __FreeBSD__
+      rawmode (0);
+#endif
     case -1:
       perror ("fork failed");
       bye (1);
@@ -276,6 +292,9 @@
       close (pspair.sfd);
     }
 
+#ifdef __FreeBSD__
+  rawmode(0);
+#endif
   setuid (getuid ());
 
   memset (&sa, 0, sizeof sa);
@@ -377,15 +396,32 @@
     {
       if ((p->mfd = open ("/dev/ptc", O_RDWR)) == -1)
 	{
-	  perror ("Cannot open cloning master pty");
-	  return -1;
+#ifdef __FreeBSD__
+#define PTYLEN	16
+	  if ((int)(sname= malloc(PTYLEN)) == -1)
+	    {
+	      perror("Cannot allocate memory");
+	      return -1;
+	    }
+          if (openpty(&p->mfd, &p->sfd, sname, NULL, NULL) == -1)
+	    {
+#endif
+	      perror ("Cannot open cloning master pty");
+	      return -1;
+#ifdef __FreeBSD__
+	    }
+#endif
 	}
     }
 
+#if !defined(__FreeBSD_version) || (defined(__FreeBSD_version) && __FreeBSD_version >= 500000)
   (void) unlockpt (p->mfd);
   (void) grantpt (p->mfd);
+#endif
 
+#ifndef __FreeBSD__
   sname = (char *) ptsname (p->mfd);
+#endif
 
   if ((p->sfd = open (sname, O_RDWR)) == -1)
     {
@@ -456,11 +492,53 @@
   abort ();
 }
 
+#ifdef __FreeBSD__
+static void
+sanemode(int ttyfd)
+{
+  static struct termios termnew;
+
+  if (tcgetattr(ttyfd, &termnew) == -1)
+    {
+      perror ("tcgetattr failed");
+      exit (1);
+    }
+  termnew.c_cflag = TTYDEF_CFLAG | (termnew.c_cflag & CLOCAL);
+  termnew.c_iflag = TTYDEF_IFLAG;
+  termnew.c_iflag |= ICRNL;
+  /* preserve user-preference flags in lflag */
+#define LKEEP   (ECHOKE|ECHOE|ECHOK|ECHOPRT|ECHOCTL|ALTWERASE|TOSTOP|NOFLSH)
+  termnew.c_lflag = TTYDEF_LFLAG | (termnew.c_lflag & LKEEP);
+  termnew.c_oflag = TTYDEF_OFLAG;
+  if (tcsetattr(ttyfd, TCSAFLUSH, &termnew) == -1)
+    {
+      perror ("tcsetattr (sane) failed");
+      exit (1);
+    }
+}
+#endif
+
 static void
 rawmode (int ttyfd)
 {
   static struct termios termnew;
 
+#ifdef __FreeBSD__
+  if (tcgetattr(ttyfd, &termnew) == -1)
+    {
+      perror ("tcgetattr failed");
+      exit (1);
+    }
+  cfmakeraw(&termnew);
+  termnew.c_cflag &= ~(CSIZE|PARENB);
+  termnew.c_cflag |= CS8;
+  if (tcsetattr(ttyfd, TCSADRAIN, &termnew) == -1)
+    {
+      perror ("tcsetattr (raw) failed");
+      exit (1);
+    }
+  return;
+#else  __FreeBSD__
 #ifdef TCGETS
   if (ioctl (ttyfd, TCGETS, &termorig) == -1)
     {
@@ -484,6 +562,7 @@
 #ifdef TCSETS
   (void) ioctl (ttyfd, TCSETS, &termnew);
 #endif
+#endif __FreeBSD__
 }
 
 static void
@@ -491,6 +570,9 @@
 {
 #ifdef TCSETS
   (void) ioctl (0, TCSETS, &termorig);
+#endif
+#ifdef __FreeBSD__
+  sanemode(0);
 #endif
 
   fclose (fttime);
