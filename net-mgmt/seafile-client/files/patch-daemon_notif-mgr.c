--- daemon/notif-mgr.c.orig	2026-11-25 21:00:21 UTC
+++ daemon/notif-mgr.c
@@ -1,6 +1,7 @@
 /* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
 
 #include "common.h"
+#define LWS_WITH_SOCKS5
 #include <libwebsockets.h>
 #include <string.h>
 #include <glib.h>
