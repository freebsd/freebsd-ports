--- src/DivertInterface.cpp.orig	2018-01-18 14:31:32 UTC
+++ src/DivertInterface.cpp
@@ -101,7 +101,7 @@ DivertInterface::DivertInterface(const char *name) : N
   sin.sin_family = AF_INET, sin.sin_port = htons(port);
   sin_len = sizeof(struct sockaddr_in);
 
-  if(bind(sock, (struct sockaddr *) &sin, sin_len) == -1) {
+  if(::bind(sock, (struct sockaddr *) &sin, sin_len) == -1) {
     ntop->getTrace()->traceEvent(TRACE_ERROR, "Unable to bind divert socket to port %d", port);
     throw 1;
   }
