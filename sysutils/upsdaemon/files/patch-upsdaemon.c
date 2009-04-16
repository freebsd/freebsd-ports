--- src/upsdaemon.c.orig	2006-06-20 01:50:23.000000000 +0100
+++ src/upsdaemon.c	2009-04-12 15:48:34.000000000 +0100
@@ -32,6 +32,7 @@
 #include <errno.h>   /* Error number definitions */
 #include <termios.h> /* POSIX terminal control definitions */
 #include <syslog.h>  /* Definitions for system error logging */
+#include <stdlib.h>  /* exit() definition */
 
 #define PROG " UpsDaemon"
 #define VERSION " 1.0"
@@ -50,6 +51,7 @@
 #define SH_RECOVERY	"/usr/local/libexec/upsdaemon/upsdaemon-alerts -recovery"
 
 int makepid(char *s);
+static void runcommand();
 
 int main(int argc, char **argv)
 {
@@ -71,7 +73,6 @@
 	char *failed    = SH_FAILED;
 	char *recovery  = SH_RECOVERY;
 		
-	static void runcommand();
 
 	if(argc > 2) {
 		errx(1,"Usage: upsdaemon <port serial open>: %s\n", strerror(errno));
