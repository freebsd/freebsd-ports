--- mutella/gnushare.cpp	Mon Nov 18 17:04:17 2002
+++ gnushare.cpp.new	Thu Jul 31 00:12:32 2003
@@ -44,6 +44,7 @@
 #include "gnuwordhash.h"
 #include "sha1thread.h"
 
+#include <assert.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
