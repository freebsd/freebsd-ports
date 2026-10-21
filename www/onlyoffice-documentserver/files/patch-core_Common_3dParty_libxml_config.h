--- core/Common/3dParty/libxml/config.h.orig	2026-10-11 14:54:04 UTC
+++ core/Common/3dParty/libxml/config.h
@@ -79,7 +79,7 @@
 #define HAVE_STDINT_H 1
 
 /* System configuration directory (/etc) */
-#define XML_SYSCONFDIR "/etc"
+#define XML_SYSCONFDIR "%%PREFIX%%/share"
 
 /* TLS specifier */
 #ifdef _WIN32
