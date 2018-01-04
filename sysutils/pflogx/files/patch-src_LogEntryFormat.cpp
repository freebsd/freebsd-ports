--- src/LogEntryFormat.cpp.orig	2006-05-08 10:23:07 UTC
+++ src/LogEntryFormat.cpp
@@ -34,6 +34,7 @@
 #include <time.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
+#include <netpfil/pf/pf.h>
 
 
 #define STATIC_BUFFER_LEN	128
