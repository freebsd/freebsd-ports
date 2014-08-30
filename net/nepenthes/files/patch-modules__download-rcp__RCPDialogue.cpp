--- modules/download-rcp/RCPDialogue.cpp.orig
+++ modules/download-rcp/RCPDialogue.cpp
@@ -27,9 +27,13 @@
 
  /* $Id: RCPDialogue.cpp 1410 2007-10-12 13:07:23Z common $ */
  
+#include <cstdlib>
+#include <cstring>
 #include <sys/types.h>
+#include <sys/socket.h>
+#include <arpa/inet.h>
 #include <netinet/in.h>
-#include <ctype.h>
+#include <cctype>
 
 #include "RCPDialogue.hpp"
 
