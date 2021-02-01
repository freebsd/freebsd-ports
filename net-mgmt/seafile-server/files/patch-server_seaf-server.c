--- server/seaf-server.c.orig	2021-01-31 19:59:11 UTC
+++ server/seaf-server.c
@@ -4,6 +4,8 @@
 
 #if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #include <event2/event.h>
+#include <event2/event_compat.h>
+#include <event2/event_struct.h>
 #else
 #include <event.h>
 #endif
