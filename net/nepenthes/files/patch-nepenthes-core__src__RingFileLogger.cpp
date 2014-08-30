--- nepenthes-core/src/RingFileLogger.cpp.orig
+++ nepenthes-core/src/RingFileLogger.cpp
@@ -27,18 +27,16 @@
 
 /* $Id: RingFileLogger.cpp 697 2006-11-11 09:17:19Z common $ */
 
-#include <time.h>
+#include <ctime>
 
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
-#include <stdio.h>
+#include <cstdio>
+#include <cstdlib>
+#include <cstring>
 #include <string>
-#include <errno.h>
-#include <sys/types.h>
-#include <sys/stat.h>
-#include <unistd.h>
-#include <errno.h>
+#include <cerrno>
 #include <pwd.h>
 #include <grp.h>
 
