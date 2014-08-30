--- nepenthes-core/src/FileLogger.cpp.orig
+++ nepenthes-core/src/FileLogger.cpp
@@ -27,15 +27,17 @@
 
 /* $Id: FileLogger.cpp 697 2006-11-11 09:17:19Z common $ */
 
-#include <time.h>
+#include <ctime>
 
 
-#include <stdio.h>
+#include <cstdio>
+#include <cstdlib>
+#include <cstring>
 #include <string>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
-#include <errno.h>
+#include <cerrno>
 #include <pwd.h>
 #include <grp.h>
 #include "FileLogger.hpp"
