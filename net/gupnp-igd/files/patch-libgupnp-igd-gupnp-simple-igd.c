--- libgupnp-igd/gupnp-simple-igd.c.orig	2011-11-08 06:37:37.000000000 +0800
+++ libgupnp-igd/gupnp-simple-igd.c	2012-05-04 01:21:02.021160345 +0800
@@ -41,6 +41,8 @@
 
 #include <string.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
+#include <sys/socket.h>
 
 #include <libgupnp/gupnp.h>
 
