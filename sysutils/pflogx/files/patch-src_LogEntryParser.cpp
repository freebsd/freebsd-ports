--- src/LogEntryParser.cpp.orig	2006-04-25 19:22:42 UTC
+++ src/LogEntryParser.cpp
@@ -35,6 +35,7 @@
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
+#include <netpfil/pf/pf.h>
 
 
 
