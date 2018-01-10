--- src/main.cpp.orig	2017-12-02 14:37:41 UTC
+++ src/main.cpp
@@ -33,7 +33,7 @@
 #include <easylogging++.h>
 
 #include "utils.hpp"
-#include "hid.hpp"
+#include "usb.hpp"
 #include "wire.hpp"
 #include "core.hpp"
 #include "http_client.hpp"
@@ -163,14 +163,12 @@ main(int argc, char *argv[])
         return 1;
     }
 
-#ifdef __linux__
     if (!vm.count("foreground")) {
         if (daemon(0, 0) < 0) {
             LOG(ERROR) << "could not daemonize";
             return 1;
         }
     }
-#endif
 
     std::string cert_data;
     std::string privkey_data;
