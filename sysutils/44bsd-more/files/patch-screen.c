diff -U8 -r ../work.orig/screen.c ./screen.c
--- ../work.orig/screen.c	Fri Jan  5 22:17:02 2001
+++ ./screen.c	Fri Jan  5 22:36:53 2001
@@ -122,17 +122,19 @@
 #define M_UL 2
 #define M_BO 4
 
 /*
  * These two variables are sometimes defined in,
  * and needed by, the termcap library.
  * It may be necessary on some systems to declare them extern here.
  */
+#if 0
 /*extern*/ speed_t ospeed;	/* Terminal output baud rate */
+#endif
 /*extern*/ char PC;		/* Pad character */
 
 extern int back_scroll;
 
 /*
  * Change terminal to "raw mode", or restore to "normal" mode.
  * "Raw mode" means
  *	1. An outstanding read will complete on receipt of a single keystroke.
