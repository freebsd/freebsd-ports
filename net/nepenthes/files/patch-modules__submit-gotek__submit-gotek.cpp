--- modules/submit-gotek/submit-gotek.cpp.orig
+++ modules/submit-gotek/submit-gotek.cpp
@@ -26,16 +26,18 @@
  *******************************************************************************/
 
  /* $Id: submit-gotek.cpp 550 2006-05-04 10:25:35Z common $ */
+#include <cstdlib>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
-#include <errno.h>
+#include <cerrno>
 #include <arpa/inet.h>
-#include <time.h>
+#include <netinet/in.h>
+#include <ctime>
 #include <dirent.h>
-#include <string.h>
-#include <errno.h>
-#include <assert.h>
+#include <cstring>
+#include <cerrno>
+#include <cassert>
 
 #include "submit-gotek.hpp"
 #include "gotekCTRLDialogue.hpp"
