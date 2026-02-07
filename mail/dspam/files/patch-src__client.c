--- src/client.c.orig   2012-04-11 18:48:33 UTC
+++ src/client.c
@@ -304,7 +304,7 @@ int client_connect(AGENT_CTX *ATX, int f
   struct sockaddr_un saun;
   int sockfd;
   int yes = 1;
-  int port = 24;
+  int port = 2424;
   int domain = 0;
   int addr_len;
   char *host;
