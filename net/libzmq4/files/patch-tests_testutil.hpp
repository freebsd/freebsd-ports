--- tests/testutil.hpp.orig	2021-01-03 21:46:02 UTC
+++ tests/testutil.hpp
@@ -45,6 +45,8 @@
 #include <arpa/inet.h>
 #include <unistd.h>
 #include <stdlib.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #endif
 
 //  This defines the settle time used in tests; raise this if we
