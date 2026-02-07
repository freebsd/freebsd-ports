--- apps/mosquitto_ctrl/ctrl_shell.c.orig	2026-02-05 18:26:53 UTC
+++ apps/mosquitto_ctrl/ctrl_shell.c
@@ -19,6 +19,7 @@ Contributors:
 #include <config.h>
 
 #include <arpa/inet.h>
+#include <netinet/in.h>
 #include <ctype.h>
 #include <errno.h>
 #include <fcntl.h>
