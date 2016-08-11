--- driftnet.c.orig	2002-07-09 19:26:41 UTC
+++ driftnet.c
@@ -254,8 +254,8 @@ void usage(FILE *fp) {
 "\n"
 "  -h               Display this help message.\n"
 "  -v               Verbose operation.\n"
-"  -i interface     Select the interface on which to listen (default: all\n"
-"                   interfaces).\n"
+"  -i interface     Select the interface on which to listen (default: first\n"
+"                   available interface).\n"
 "  -p               Do not put the listening interface into promiscuous mode.\n""  -a               Adjunct mode: do not display images on screen, but save\n"
 "                   them to a temporary directory and announce their names on\n"
 "                   standard output.\n"
@@ -313,7 +313,7 @@ void terminate_on_signal(int s) {
 void setup_signals(void) {
     int *p;
     /* Signals to ignore. */
-    int ignore_signals[] = {SIGPIPE, 0};
+    int ignore_signals[] = {SIGPIPE, SIGCONT, SIGHUP, 0};
     /* Signals which mean we should quit, killing the display child if
      * applicable. */
     int terminate_signals[] = {SIGTERM, SIGINT, /*SIGSEGV,*/ SIGBUS, SIGCHLD, 0};
