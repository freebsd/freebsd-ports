--- screen.c.orig	Mon Feb 24 12:45:41 1992
+++ screen.c	Sat May 20 01:40:56 2000
@@ -481,5 +481,5 @@
  */
 	public void
-clear()
+clearscr()
 {
 	tputs(sc_clear, sc_height, putchr);
