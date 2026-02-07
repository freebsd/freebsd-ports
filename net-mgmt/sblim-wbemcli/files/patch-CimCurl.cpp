--- CimCurl.cpp.orig	2013-09-20 23:26:32 UTC
+++ CimCurl.cpp
@@ -27,6 +27,7 @@
 #include <string.h>
 #endif
 
+#include <unistd.h>
 #include "CimCurl.h"
 #include <unistd.h> // for getpass()
 #include <cerrno> 
