#
# enable copying of fifos/sockets
#  <http://lists.samba.org/archive/rsync/2002-June/002966.html>
#  <http://www.freebsd.org/cgi/query-pr.cgi?pr=59814>
#
--- rsync.h.orig	Tue Aug 24 16:37:59 2004
+++ rsync.h	Tue Aug 24 16:38:28 2004
@@ -156,6 +156,10 @@
 #include <sys/socket.h>
 #endif
 
+#ifdef HAVE_SYS_UN_H
+#include <sys/un.h>
+#endif
+
 #ifdef HAVE_STRING_H
 #include <string.h>
 #endif
