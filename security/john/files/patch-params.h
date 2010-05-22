--- src/params.h.orig
+++ src/params.h
@@ -101,7 +101,11 @@
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
