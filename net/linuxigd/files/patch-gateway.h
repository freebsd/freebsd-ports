--- gateway.h.orig	Fri May  3 00:14:57 2002
+++ gateway.h	Sat Aug  3 22:10:54 2002
@@ -28,7 +28,7 @@
 
 #define INIT_PORT          2869
 #define INIT_DESC_DOC      "gatedesc"
-#define INIT_CONF_DIR      "/etc/linuxigd/"
+#define INIT_CONF_DIR      "%%PREFIX%%/etc/linuxigd/"
 
 #define GATE_SERVICE_SERVCOUNT  3
 #define GATE_SERVICE_OSINFO             0
