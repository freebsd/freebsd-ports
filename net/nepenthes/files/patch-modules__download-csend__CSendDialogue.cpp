--- modules/download-csend/CSendDialogue.cpp.orig
+++ modules/download-csend/CSendDialogue.cpp
@@ -27,7 +27,10 @@
 
  /* $Id: CSendDialogue.cpp 2271 2006-01-14 20:31:52Z common $ */
  
+#include <cstdlib>
 #include <sys/types.h>
+#include <sys/socket.h>
+#include <arpa/inet.h>
 #include <netinet/in.h>
 
 #include "CSendDialogue.hpp"
