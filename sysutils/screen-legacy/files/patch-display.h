--- display.h.orig	2003-07-01 07:01:42.000000000 -0700
+++ display.h	2011-11-07 11:54:32.842183150 -0800
@@ -85,7 +85,7 @@
   struct win *d_other;		/* pointer to other window */
   int   d_nonblock;		/* -1 don't block if obufmax reached */
 				/* >0: block after nonblock secs */
-  char  d_termname[20 + 1];	/* $TERM */
+  char  d_termname[63 + 1];	/* $TERM */
   char	*d_tentry;		/* buffer for tgetstr */
   char	d_tcinited;		/* termcap inited flag */
   int	d_width, d_height;	/* width/height of the screen */
