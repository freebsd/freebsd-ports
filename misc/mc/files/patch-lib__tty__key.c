--- ./lib/tty/key.c.orig	2013-11-29 19:27:07.000000000 +0100
+++ ./lib/tty/key.c	2013-12-07 10:51:45.000000000 +0100
@@ -1946,6 +1946,7 @@
 tty_get_event (struct Gpm_Event *event, gboolean redo_event, gboolean block)
 {
     int c;
+    static int flag = 0;        /* Return value from select */
 #ifdef HAVE_LIBGPM
     static struct Gpm_Event ev; /* Mouse event */
 #endif
@@ -1978,7 +1979,6 @@
     while (pending_keys == NULL)
     {
         int nfd;
-        static int flag = 0;    /* Return value from select */
         fd_set select_set;
 
         FD_ZERO (&select_set);
