--- src/masqmail.c.old	Mon Apr  5 01:18:16 2004
+++ src/masqmail.c	Mon Apr  5 01:23:09 2004
@@ -167,7 +167,7 @@
 
   DEBUG(5) debugf("accepting smtp message on stdin\n");
 
-  if(getpeername(0, &saddr, &dummy) == 0){
+  if(getpeername(0, (struct sockaddr *)(&saddr), &dummy) == 0){
     peername = g_strdup(inet_ntoa(saddr.sin_addr));
 #ifdef ENABLE_IDENT
     {
