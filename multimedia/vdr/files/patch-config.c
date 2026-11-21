--- config.c.orig	2026-10-27 18:57:48 UTC
+++ config.c
@@ -10,7 +10,9 @@
 #define MUTE_DEPRECATED_USEDOLBYDIGITAL
 #include "config.h"
 #include <ctype.h>
+#include <netinet/in.h>
 #include <stdlib.h>
+#include <sys/socket.h>
 #include "device.h"
 #include "i18n.h"
 #include "interface.h"
