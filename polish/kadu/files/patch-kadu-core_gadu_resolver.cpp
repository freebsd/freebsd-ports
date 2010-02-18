--- kadu-core/gadu_resolver.cpp.orig	2009-10-18 10:00:12.000000000 +0200
+++ kadu-core/gadu_resolver.cpp	2010-02-16 01:41:36.000000000 +0100
@@ -9,6 +9,7 @@
 #include <io.h>
 #else
 #include <sys/wait.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #include <arpa/inet.h>
 #endif
