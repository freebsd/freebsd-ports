--- src/modules/ctl/ctl_defaults.h.orig	2018-03-01 16:24:09 UTC
+++ src/modules/ctl/ctl_defaults.h
@@ -13,7 +13,7 @@
 #define DEFAULT_CTL_SOCKET_NAME NAME "_ctl"
 #endif
 
-#define DEFAULT_CTL_SOCKET DEFAULT_CTL_SOCKET_PROTO RUN_DIR "/" DEFAULT_CTL_SOCKET_NAME
+#define DEFAULT_CTL_SOCKET DEFAULT_CTL_SOCKET_PROTO "/var/run/" DEFAULT_CTL_SOCKET_NAME
 
 /* port used by default for tcp/udp if no port is explicitely specified */
 #define DEFAULT_CTL_PORT 2049
