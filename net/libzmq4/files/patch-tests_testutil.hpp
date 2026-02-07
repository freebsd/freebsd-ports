--- tests/testutil.hpp.orig	2023-06-18 14:40:34 UTC
+++ tests/testutil.hpp
@@ -23,6 +23,8 @@
 #include <arpa/inet.h>
 #include <unistd.h>
 #include <stdlib.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #endif
 
 //  This defines the settle time used in tests; raise this if we
