--- prim.c.orig	2011-09-08 01:21:48.000000000 +0800
+++ prim.c	2011-09-08 01:23:17.000000000 +0800
@@ -66,11 +66,12 @@ extern int retain_below;
 
 off_t position(), forw_line(), back_line(), forw_raw_line(), back_raw_line();
 off_t ch_length(), ch_tell();
+void jump_loc(off_t);
 
 /*
  * Check to see if the end of file is currently "displayed".
  */
-static
+static void
 eof_check()
 {
 	off_t pos;
@@ -256,6 +257,7 @@ back(n, pos, only_last)
  * Display n more lines, forward.
  * Start just after the line currently displayed at the bottom of the screen.
  */
+void
 forward(n, only_last)
 	int n;
 	int only_last;
@@ -284,6 +286,7 @@ forward(n, only_last)
  * Display n more lines, backward.
  * Start just before the line currently displayed at the top of the screen.
  */
+void
 backward(n, only_last)
 	int n;
 	int only_last;
@@ -328,6 +331,7 @@ repaint()
  * It is more convenient to paint the screen backward,
  * from the end of the file toward the beginning.
  */
+void
 jump_forw()
 {
 	off_t pos;
@@ -348,6 +352,7 @@ jump_forw()
 /*
  * Jump to line n in the file.
  */
+void
 jump_back(n)
 	register int n;
 {
@@ -393,6 +398,7 @@ jump_back(n)
  * This is a poor compensation for not being able to
  * quickly jump to a specific line number.
  */
+void
 jump_percent(percent)
 	int percent;
 {
@@ -427,6 +433,7 @@ jump_percent(percent)
 /*
  * Jump to a specified position in the file.
  */
+void
 jump_loc(pos)
 	off_t pos;
 {
