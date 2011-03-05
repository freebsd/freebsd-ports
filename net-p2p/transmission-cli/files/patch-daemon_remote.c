--- daemon/remote.c~
+++ daemon/remote.c
@@ -38,7 +38,7 @@
 #include <libtransmission/version.h>
 
 #define MY_NAME "transmission-remote"
-#define DEFAULT_HOST "localhost"
+#define DEFAULT_HOST "127.0.0.1"
 #define DEFAULT_PORT atoi(TR_DEFAULT_RPC_PORT_STR)
 #define DEFAULT_URL TR_DEFAULT_RPC_URL_STR "rpc/"
 
