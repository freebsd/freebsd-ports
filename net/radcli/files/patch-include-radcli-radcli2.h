--- include/radcli/radcli2.h.orig	2026-09-13 10:03:44 UTC
+++ include/radcli/radcli2.h
@@ -53,6 +53,7 @@
 #include <stdint.h>
 #include <stddef.h>
 #include <netinet/in.h>
+#include <sys/socket.h>
 #include <poll.h> /* struct pollfd, radcli_ctx_get_poll() */
 #include <radcli/radcli-defs.h>
 
