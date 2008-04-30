--- xio.c.orig	2007-12-03 06:18:04.000000000 +0000
+++ xio.c	2008-04-30 12:37:57.000000000 +0000
@@ -156,6 +156,7 @@
 }
 
 
+static void handle_event(); //forward ref
 
 struct xio *
 xio_open_dpy(char *dpy, int argc, char **argv)
