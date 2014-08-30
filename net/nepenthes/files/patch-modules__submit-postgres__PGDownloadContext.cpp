--- modules/submit-postgres/PGDownloadContext.cpp.orig
+++ modules/submit-postgres/PGDownloadContext.cpp
@@ -38,9 +38,11 @@
 #include <sys/stat.h>
 #include <unistd.h>
 
-#include <time.h>
-#include <errno.h>
-#include <string.h>
+#include <cstdio>
+#include <cstdlib>
+#include <ctime>
+#include <cerrno>
+#include <cstring>
 
 #include <sstream>
 #include <map>
