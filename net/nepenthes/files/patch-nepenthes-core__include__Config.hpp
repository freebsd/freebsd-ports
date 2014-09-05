--- nepenthes-core/include/Config.hpp.orig
+++ nepenthes-core/include/Config.hpp
@@ -44,12 +44,14 @@
 #include <sys/stat.h>
 #include <unistd.h>
 // errno()
-#include <errno.h>
+#include <cerrno>
 // open()
 #include <fcntl.h>
 
 #include <stdint.h>
 
+#include <cstring>
+
 #endif
 
 using namespace std;
