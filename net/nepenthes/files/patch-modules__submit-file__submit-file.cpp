--- modules/submit-file/submit-file.cpp.orig
+++ modules/submit-file/submit-file.cpp
@@ -26,10 +26,11 @@
  *******************************************************************************/
 
  /* $Id: submit-file.cpp 550 2006-05-04 10:25:35Z common $ */
+#include <cstdio>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
-#include <errno.h>
+#include <cerrno>
 
 #include "submit-file.hpp"
 #include "Download.hpp"
