--- src/mserver.c.old	Mon Mar 19 17:45:28 2001
+++ src/mserver.c	Mon Apr  5 01:27:29 2004
@@ -56,7 +56,7 @@
   if(init_sockaddr(&saddr, conf.mserver_iface)){
     int sock = socket(PF_INET, SOCK_STREAM, 0);
     int dup_sock;
-    if(connect(sock, &saddr, sizeof(saddr)) == 0){
+    if(connect(sock, (struct sockaddr *)(&saddr), sizeof(saddr)) == 0){
       FILE *in, *out;
       char buf[256];
 
