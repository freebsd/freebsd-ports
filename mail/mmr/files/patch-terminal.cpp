--- terminal.cpp.orig	Fri Oct 25 13:51:29 2002
+++ terminal.cpp	Fri Oct 25 13:51:50 2002
@@ -11,7 +11,7 @@
 int Terminal::wasraw = 0;
 int Terminal::maxwait = 0;
 
-Terminal:: Terminal(int makeraw = 1)
+Terminal:: Terminal(int makeraw)
 {
 	/* Initialize curses, if necessary */
 	if ( refcount == 0 ) {
@@ -133,7 +133,7 @@
 
 /* Input routines */
 int
-Terminal:: waitchar(WINDOW *the_win = NULL)
+Terminal:: waitchar(WINDOW *the_win)
 {
 	int ch, t;
 
