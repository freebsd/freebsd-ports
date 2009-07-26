--- main.c.orig	2006-04-23 09:38:25.000000000 +0200
+++ main.c	2009-07-26 17:00:09.000000000 +0200
@@ -49,7 +49,7 @@
 Initialize(int argc, char *argv[])
 {
 	sigset_t signalset;
-	struct ttysize ts;
+	struct winsize ws;
 	char *diskname;
 
 	Fake			 = FALSE;
@@ -59,11 +59,11 @@
 
 	diskname = check_arg(argc, argv);
 
-	if (ioctl(0, TIOCGSIZE, &ts) == -1) {
+	if (ioctl(0, TIOCGWINSZ, &ws) == -1) {
        msgDebug("Unable to get terminal size - errno %d\n", errno);
-       ts.ts_lines = 0;
+       ws.ws_row = 0;
 	}
-	StatusLine = ts.ts_lines ? ts.ts_lines - 1: TTY_STATUS_LINE;
+	StatusLine = ws.ws_row ? ws.ws_row - 1: TTY_STATUS_LINE;
 
     init_dialog();
 
