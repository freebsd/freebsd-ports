$FreeBSD$

--- src/wrappers.h.orig	Mon Mar 29 12:57:11 2004
+++ src/wrappers.h	Mon Mar 29 13:46:45 2004
@@ -35,9 +35,14 @@
 #include <sys/time.h>
 #include <time.h>
 #include <regex.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #if HAVE_POLL
 #include <sys/poll.h>
+#endif
+
+#ifdef __FreeBSD__
+#define REG_NOERROR 0
 #endif
 
 /*
