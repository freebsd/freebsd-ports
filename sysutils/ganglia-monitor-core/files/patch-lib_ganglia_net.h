
$FreeBSD$

--- lib/ganglia/net.h.orig	Mon Oct 27 16:53:00 2003
+++ lib/ganglia/net.h	Mon Oct 27 16:53:07 2003
@@ -12,7 +12,7 @@
 #include <netdb.h>
 #include <ganglia/llist.h>
 #include <ganglia/net.h>
-#ifdef BSD
+#ifdef FREEBSD
 #include <sys/types.h>
 #endif
 #include <netinet/in.h>
