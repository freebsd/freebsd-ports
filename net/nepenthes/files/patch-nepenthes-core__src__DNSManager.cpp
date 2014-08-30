--- nepenthes-core/src/DNSManager.cpp.orig
+++ nepenthes-core/src/DNSManager.cpp
@@ -33,7 +33,8 @@
 #include <poll.h>
 #endif
 
-#include <errno.h>
+#include <cstring>
+#include <cerrno>
 #include "DNSManager.hpp"
 #include "DNSCallback.hpp"
 #include "DNSResult.hpp"
