--- mod_traffic.c.orig	2013-07-01 18:43:14 UTC
+++ mod_traffic.c
@@ -291,7 +291,7 @@ IncludePorts(
 
 
 
-static int
+static void
 traffic_init_files(void)
 {
     static int created = 0;
