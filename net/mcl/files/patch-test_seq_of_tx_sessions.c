--- check/alc/test_seq_of_tx_sessions.c.orig	Tue Jul 22 19:37:39 2003
+++ check/alc/test_seq_of_tx_sessions.c	Wed Oct 15 17:11:13 2003
@@ -25,6 +25,11 @@
  */
 
 #include <stdio.h>
+
+#ifdef FREEBSD
+#include <sys/types.h>
+#endif
+
 #ifdef WIN32
 #include <winsock2.h>
 #else
