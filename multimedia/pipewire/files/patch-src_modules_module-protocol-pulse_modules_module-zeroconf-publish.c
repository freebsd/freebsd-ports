--- src/modules/module-protocol-pulse/modules/module-zeroconf-publish.c.orig	2022-11-24 08:57:59 UTC
+++ src/modules/module-protocol-pulse/modules/module-zeroconf-publish.c
@@ -25,6 +25,7 @@
 
 #include <sys/utsname.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
 
 #include <pipewire/pipewire.h>
 
