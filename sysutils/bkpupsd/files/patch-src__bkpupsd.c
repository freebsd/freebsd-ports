--- src/bkpupsd.c.orig	Sun Aug  3 20:11:23 1997
+++ src/bkpupsd.c	Fri Dec 15 00:53:52 2006
@@ -27,14 +27,17 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <unistd.h>
 #include <fcntl.h>
 #include <err.h>
 #include <errno.h>
+#include <string.h>
 #include <sys/types.h>
 #include <sys/ioctl.h>
 #include <signal.h>
 #include <syslog.h>
-#include <varargs.h>
+#include <stdarg.h>
 
 #define POWER_TIMEOUT		5*60
 #define DEFAULT_PORT		"/dev/cuaa1"
@@ -44,16 +47,17 @@
 #define SH_RESTORED		"/usr/local/libexec/bkpupsd/bkpups.restored"
 #define SH_BATTLOW		"/usr/local/libexec/bkpupsd/bkpups.battlow"
 
+int makepid(char *s);
+void execomand();
+
 int main(argc, argv)
 int argc;
 char  **argv;
 {
 	int fd;
 	int lstatus;
-	int flags;
 	int rts_bit = TIOCM_RTS;
 	int dtr_bit = TIOCM_DTR;
-	int rng_bit = TIOCM_RNG;
 	int pfail = 0;
 	int pfcount = 0;
 	int prcount = 0;
@@ -63,7 +67,6 @@
 	char *sh_restored = SH_RESTORED;
 	char *sh_battlow  = SH_BATTLOW;
 	char *ups_port	  = DEFAULT_PORT;
-	static void execomand();
 
 		/* open ups port */
 	if(argc > 2) {
@@ -179,7 +182,7 @@
 	pid = getpid();
 	if((fp =  fopen(s, "w")) == NULL)
 		return -1;
-	fprintf(fp, "%ld\n", pid);
+	fprintf(fp, "%lu\n", (u_long)pid);
 	fclose(fp);
 	return 0;
 }
