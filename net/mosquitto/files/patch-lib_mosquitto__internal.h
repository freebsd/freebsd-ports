--- lib/mosquitto_internal.h.orig	2026-02-05 18:32:43 UTC
+++ lib/mosquitto_internal.h
@@ -22,6 +22,7 @@ Contributors:
 
 #include "config.h"
 
+#include <sys/types.h>
 #ifdef WIN32
 #  include <winsock2.h>
 #endif
