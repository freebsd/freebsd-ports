--- ssl/test/handshake_util.cc.orig	2022-01-03 17:27:50 UTC
+++ ssl/test/handshake_util.cc
@@ -21,8 +21,14 @@
 #include <spawn.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
+#ifdef __FreeBSD__
+#include <sys/signal.h>
+#endif
 #include <sys/types.h>
 #include <sys/wait.h>
+#ifdef __FreeBSD__
+#include <signal.h>
+#endif
 #include <unistd.h>
 #endif
 
@@ -37,6 +43,10 @@
 
 #include <openssl/bytestring.h>
 #include <openssl/ssl.h>
+
+#ifdef __FreeBSD__
+extern char **environ;
+#endif
 
 using namespace bssl;
 
