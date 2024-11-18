https://gitlab.freedesktop.org/mstoeckl/waypipe/-/issues/110

--- src/secctx.c.orig	2024-11-18 22:29:20 UTC
+++ src/secctx.c
@@ -1,5 +1,6 @@
 #include "security-context-v1-protocol.h"
 #include "util.h"
+#include <string.h>
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <unistd.h>
