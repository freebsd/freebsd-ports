--- bjoern/server.c.orig	2011-03-23 19:02:58.000000000 +0100
+++ bjoern/server.c	2011-12-17 22:10:03.000000000 +0100
@@ -1,11 +1,17 @@
-#include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <fcntl.h>
 #ifdef WANT_SIGINT_HANDLING
 # include <sys/signal.h>
 #endif
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <sys/uio.h>
+#elif defined(__linux__)
+#include <sys/socket.h>
 #include <sys/sendfile.h>
+#endif
 #include <ev.h>
 #include "common.h"
 #include "wsgi.h"
@@ -294,7 +300,9 @@
   Py_ssize_t bytes_sent = sendfile(
     request->client_fd,
     request->current_chunk_p, /* current_chunk_p stores the file fd */
-    NULL, SENDFILE_CHUNK_SIZE
+    NULL, SENDFILE_CHUNK_SIZE,
+    NULL, NULL,
+    SF_NODISKIO
   );
   if(bytes_sent == -1)
     return handle_nonzero_errno(request);
