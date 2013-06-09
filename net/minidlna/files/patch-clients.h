diff --git clients.h clients.h
index d3ffe1d..2a4c579 100644
--- clients.h
+++ clients.h
@@ -1,6 +1,7 @@
 #ifndef __CLIENTS_H__
 #define __CLIENTS_H__
 #include <stdint.h>
+#include <sys/time.h>
 #include <netinet/in.h>
 
 #define CLIENT_CACHE_SLOTS 20
