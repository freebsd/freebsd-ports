--- mutella/gnudownload.cpp	Wed Jan 22 14:48:30 2003
+++ gnudownload.cpp.new	Thu Jul 31 00:26:42 2003
@@ -43,6 +43,7 @@
 #include "property.h"
 #include "preferences.h"
 
+#include <assert.h>
 #include <unistd.h>
 #include <sys/ioctl.h>
 #include <sys/stat.h>
