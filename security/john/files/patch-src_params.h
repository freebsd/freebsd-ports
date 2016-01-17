--- src/params.h.orig	2012-09-20 14:35:00 UTC
+++ src/params.h
@@ -134,7 +134,11 @@
 /*
  * File names.
  */
+#if JOHN_SYSTEMWIDE
+#ifndef CFG_FULL_NAME
 #define CFG_FULL_NAME			"$JOHN/john.conf"
+#endif
+#endif
 #define CFG_ALT_NAME			"$JOHN/john.ini"
 #if JOHN_SYSTEMWIDE
 #define CFG_PRIVATE_FULL_NAME		JOHN_PRIVATE_HOME "/john.conf"
