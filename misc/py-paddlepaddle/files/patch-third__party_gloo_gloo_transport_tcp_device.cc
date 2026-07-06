-- Add missing #include <array> required for std::array used in device.cc.
--- third_party/gloo/gloo/transport/tcp/device.cc.orig	2022-08-30 11:33:00 UTC
+++ third_party/gloo/gloo/transport/tcp/device.cc
@@ -12,6 +12,7 @@
 #include <netdb.h>
 #include <netinet/in.h>
 #include <string.h>
+#include <array>
 
 #include "gloo/common/linux.h"
 #include "gloo/common/logging.h"
