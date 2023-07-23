--- src/knock.c.orig	2023-07-23 20:01:56 UTC
+++ src/knock.c
@@ -35,7 +35,7 @@
 #include <getopt.h>
 #include <fcntl.h>
 
-static char version[] = "0.8";
+static char version[] = "#VERSION#";
 
 #define PROTO_TCP 1
 #define PROTO_UDP 2
