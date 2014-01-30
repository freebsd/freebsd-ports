--- ./example/protocol/Protocol.c.orig	2013-12-05 22:07:48.000000000 +0000
+++ ./example/protocol/Protocol.c	2014-01-27 08:45:49.000000000 +0000
@@ -104,6 +104,7 @@
 TSPluginInit(int argc, const char *argv[])
 {
   TSPluginRegistrationInfo info;
+  char *end;
 
   info.plugin_name = "output-header";
   info.vendor_name = "MyCompany";
@@ -124,17 +125,19 @@
     printf("[protocol_plugin] Usage: protocol.so accept_port server_port\n");
     printf("[protocol_plugin] Wrong arguments. Using deafult ports.\n");
   } else {
-    if (!isnan(atoi(argv[1]))) {
-      accept_port = atoi(argv[1]);
+    strtol(argv[1], &end, 10);
+    if (*end == '\0') {
+      accept_port = strtol(argv[1], &end, 10);
       TSDebug("protocol", "using accept_port %d", accept_port);
       printf("[protocol_plugin] using accept_port %d\n", accept_port);
     } else {
       printf("[protocol_plugin] Wrong argument for accept_port.");
       printf("Using deafult port %d\n", accept_port);
     }
-
-    if (!isnan(atoi(argv[2]))) {
-      server_port = atoi(argv[2]);
+  
+    strtol(argv[2], &end, 10);
+    if (*end == '\0') {
+      server_port = strtol(argv[2], &end, 10);
       TSDebug("protocol", "using server_port %d", server_port);
       printf("[protocol_plugin] using server_port %d\n", server_port);
     } else {
