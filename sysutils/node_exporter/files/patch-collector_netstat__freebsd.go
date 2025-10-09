--- collector/netstat_freebsd.go.orig	2025-10-09 18:59:35 UTC
+++ collector/netstat_freebsd.go
@@ -28,6 +28,7 @@ import (
 
 /*
 #include <sys/types.h>
+#include <sys/queue.h>
 #include <netinet/in.h>
 #include <netinet/ip.h>
 #include <netinet/tcp.h>
