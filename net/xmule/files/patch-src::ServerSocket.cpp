--- src/ServerSocket.cpp.orig	Sun Nov 14 19:41:57 2004
+++ src/ServerSocket.cpp	Sun Nov 14 19:42:03 2004
@@ -44,6 +44,7 @@
 
 #include "DynPrefs/DynPrefs.h"              // Needed for DynamicPreferences
 
+#include <netinet/in.h>
 #include <arpa/inet.h>                      // Needed for sockaddr_in
 
 class ServerSocketEvt: public wxEvtHandler
