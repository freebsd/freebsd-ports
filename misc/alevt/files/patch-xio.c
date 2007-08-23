--- xio.c.orig	2002-08-20 05:09:38.000000000 +0200
+++ xio.c	2007-08-23 07:48:59.587926513 +0200
@@ -31,11 +31,11 @@
 
 static struct dl_head dpys[1];		/* list of all displays */
 
+static void xio_timer();
 
 static int
 timer_init(int argc, char **argv)
 {
-    static void xio_timer();
     int p[2], timer_pid, i;
 
     if (pipe(p) == -1)
@@ -154,13 +154,12 @@
 	fdset_del_fd(fds, fd);
 }
 
-
+static void handle_event(); //forward ref
 
 struct xio *
 xio_open_dpy(char *dpy, int argc, char **argv)
 {
     XClassHint classhint[1];
-    static void handle_event(); //forward ref
     struct xio *xio;
 
     if (local_init(argc, argv) == -1)
