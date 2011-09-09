--- signal.c.orig	2011-09-08 01:24:01.000000000 +0800
+++ signal.c	2011-09-08 01:24:09.000000000 +0800
@@ -160,6 +160,7 @@ init_signals(on)
  * Process any signals we have received.
  * A received signal cause a bit to be set in "sigs".
  */
+void
 psignals()
 {
 	register int tsignals;
