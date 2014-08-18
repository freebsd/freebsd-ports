--- ./apt-pkg/contrib/fileutl.h.orig	2014-08-16 19:31:39.000000000 -0400
+++ ./apt-pkg/contrib/fileutl.h	2014-08-16 19:31:52.000000000 -0400
@@ -25,6 +25,7 @@
 #pragma interface "apt-pkg/fileutl.h"
 #endif 
 
+#include <sys/types.h>
 #include <string>
 
 using std::string;
