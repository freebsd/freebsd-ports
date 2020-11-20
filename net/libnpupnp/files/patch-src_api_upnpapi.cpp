--- src/api/upnpapi.cpp.orig	2020-11-13 17:15:32 UTC
+++ src/api/upnpapi.cpp
@@ -39,6 +39,8 @@
 #include <utility>
 #include <mutex>
 #include <thread>
+#include <array>
+
 #include <curl/curl.h>
 
 #include "upnpapi.h"
