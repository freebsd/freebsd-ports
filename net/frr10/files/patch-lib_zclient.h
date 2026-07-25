--- lib/zclient.h.orig	2026-06-01 18:27:57 UTC
+++ lib/zclient.h
@@ -420,7 +420,7 @@ extern int zclient_bfd_session_update(ZAPI_CALLBACK_AR
 #define ZAPI_MESSAGE_SRTE 0x0200
 #define ZAPI_MESSAGE_OPAQUE 0x0400
 
-#define ZSERV_VERSION 6
+#define ZSERV_VERSION 7
 /* Zserv protocol message header */
 struct zmsghdr {
 	uint16_t length;
