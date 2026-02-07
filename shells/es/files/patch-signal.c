--- signal.c.orig	Sat Apr 12 04:54:37 1997
+++ signal.c	Sat Oct 12 23:33:16 2002
@@ -68,7 +68,7 @@
 
 /* catcher -- catch (and defer) a signal from the kernel */
 static void catcher(int sig) {
-#if !SYSV_SIGNALS /* only do this for unreliable signals */
+#if SYSV_SIGNALS /* only do this for unreliable signals */
 	signal(sig, catcher);
 #endif
 	if (hasforked)
