--- libproxy/url.cpp~
+++ libproxy/url.cpp
@@ -27,6 +27,7 @@
 #define close _close
 #endif
 #include <fcntl.h> // For ::open()
+#include <unistd.h> // For close()
 #include <cstring> // For memcpy()
 #include <sstream> // For int/string conversion (using stringstream)
 #include <cstdio>  // For sscanf()
