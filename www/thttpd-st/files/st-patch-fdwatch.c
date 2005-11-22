--- fdwatch.c.orig	Thu Dec 25 22:05:04 2003
+++ fdwatch.c	Wed Sep 21 22:49:32 2005
@@ -59,6 +59,11 @@
 
 #include "fdwatch.h"
 
+#undef HAVE_KQUEUE
+#undef HAVE_SELECT
+#undef HAVE_POLL
+#define HAVE_POLL
+
 #ifdef HAVE_SELECT
 #ifndef FD_SET
 #define NFDBITS         32
@@ -613,7 +618,7 @@
     {
     int r, ridx, i;
 
-    r = poll( pollfds, npoll_fds, (int) timeout_msecs );
+    r = st_poll( pollfds, npoll_fds, (unsigned long long) (timeout_msecs * (timeout_msecs == INFTIM ? 1 : 1000)) );
     if ( r <= 0 )
 	return r;
 
