--- mod_throttle.c.orig	Mon Oct 28 00:50:56 2002
+++ mod_throttle.c	Mon Oct 28 00:51:06 2002
@@ -41,6 +41,10 @@
  * for a FreeBSD machine for testing and several suggestions.
  */
 
+#ifdef INET6
+#error mod_throttle is not IPv6-aware.
+#endif
+
 /***********************************************************************
  *** Pick one that best suits your system.
  ***********************************************************************/
