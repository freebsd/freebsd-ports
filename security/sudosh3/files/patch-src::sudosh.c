--- src/sudosh.c	2009-11-27 05:19:58.000000000 -0500
+++ src/sudosh.c	2013-02-12 16:10:41.000000000 -0500
@@ -28,4 +28,11 @@
 #define WRITE(a, b, c) do_write(a, b, c, __FILE__, __LINE__)
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <libutil.h>
+#include <sys/param.h>
+#endif
+
 typedef enum {false=0, true=1} bool;
 
@@ -94,5 +101,5 @@
 static int findms (struct pst *);
 void mysyslog (int, const char *, ...);
-char *rand2str (size_t len);
+const char *rand2str (size_t len);
 int do_write (int, void *, size_t, char *, unsigned int);
 
@@ -109,10 +116,9 @@
 extern int optind;
 
-int main (int argc, char *argv[], char *environ[])
+int main(int argc, char *argv[])
 {
 	int result = EXIT_SUCCESS;
 //	int n = 1;
 	int valid = -1;
-	int found = FALSE;
 //	char iobuf[BUFSIZ];
 	char sysconfdir[BUFSIZ];
@@ -120,6 +126,5 @@
 	char c_command[BUFSIZ];
 	char *p = NULL;
-	char *c_args = NULL;
-	char *rand = rand2str (16);
+	const char *rand = rand2str (16);
 	time_t now = time ((time_t *) NULL);
 	struct stat s;
@@ -178,13 +183,11 @@
 				strncpy (c_str, optarg, BUFSIZ - 1);
 				strncpy (c_command, optarg, BUFSIZ -1);
-				c_args = (char *) strchr (optarg, ' ');
 				p=strchr(c_str, ' ');
 
 				if (p) {
 					p[0]=0;
-				//	fprintf(stderr,"args=%s\n",c_args);
 				}
 
-				if (c_str) {
+				{
 				//	fprintf(stderr,"Testing c\n");
 					// Make sure that c_str is in argallow
@@ -444,10 +447,30 @@
 	char *sname;
 
+#ifdef __FreeBSD__
+#define PTYLEN        16
+	char sname_area[PTYLEN];
+	struct termios tt;
+	struct winsize win;
+
+	sname = sname_area;
+	if (tcgetattr(STDIN_FILENO, &tt) == -1) {
+		perror ("tcgetattr");
+		return -1;
+	}
+	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &win) == -1) {
+		perror ("ioctl");
+		return -1;
+	}
+	if (openpty(&p->mfd, &p->sfd, sname, &tt, &win) == -1) {
+#else
 	if ((p->mfd = open ("/dev/ptmx", O_RDWR)) == -1) {
 
 		if ((p->mfd = open ("/dev/ptc", O_RDWR)) == -1) {
+#endif
 			perror ("Cannot open cloning master pty");
 			return -1;
+#ifndef __FreeBSD__
 		}
+#endif
 	}
 
@@ -516,7 +539,12 @@
 		close (i);
 
+#ifdef __FreeBSD__
+	(void) tcsetattr(0, TCSADRAIN, &termorig);
+	(void) login_tty(pst->sfd);
+#else
 #ifdef TCSETS
 	(void) ioctl (0, TCSETS, &termorig);
 #endif
+#endif
 	(void) ioctl (0, TIOCSWINSZ, &winorig);
 
@@ -672,4 +700,11 @@
 	static struct termios termnew;
 
+#ifdef __FreeBSD__
+  if (tcgetattr(ttyfd, &termorig) == -1)
+    {
+      perror ("tcgetattr failed");
+      exit (EXIT_FAILURE);
+    }
+#else
 #ifdef TCGETS
 	if (ioctl (ttyfd, TCGETS, &termorig) == -1) {
@@ -678,4 +713,5 @@
 	}
 #endif
+#endif
 
 	if (ioctl (ttyfd, TIOCGWINSZ, &winorig) == -1) {
@@ -686,4 +722,9 @@
 	}
 
+#ifdef __FreeBSD__
+	(void) cfmakeraw(&termnew);
+	termnew.c_lflag &= ~ECHO;
+	(void) tcsetattr(ttyfd, TCSAFLUSH, &termnew);
+#else
 	termnew.c_cc[VEOF] = 1;
 	termnew.c_iflag = BRKINT | ISTRIP | IXON | IXANY;
@@ -695,11 +736,16 @@
 	(void) ioctl (ttyfd, TCSETS, &termnew);
 #endif
+#endif
 }
 
 static void bye (int signum)
 {
+#ifdef __FreeBSD__
+	(void) tcsetattr(0, TCSADRAIN, &termorig);
+#else
 #ifdef TCSETS
 	(void) ioctl (0, TCSETS, &termorig);
 #endif
+#endif
 
 	close (timing.fd);
@@ -713,5 +759,5 @@
 }
 
-static void newwinsize (int signum)
+static void newwinsize (int signum __unused)
 {
 	int fd;
