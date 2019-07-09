--- src/framework/socketreceiver.h.orig	2019-07-05 19:04:13 UTC
+++ src/framework/socketreceiver.h
@@ -3,6 +3,9 @@
 
 #pragma once
 
+// work around broken? _ALIGN/_ALIGNBYTES on FreeBSD powerpc
+#include <sys/types.h>
+
 #include <sys/socket.h>
 #include "serversocket.h"
 class SocketConnection;
