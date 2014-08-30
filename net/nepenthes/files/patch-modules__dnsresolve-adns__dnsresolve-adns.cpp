--- modules/dnsresolve-adns/dnsresolve-adns.cpp.orig
+++ modules/dnsresolve-adns/dnsresolve-adns.cpp
@@ -28,7 +28,8 @@
  /* $Id: dnsresolve-adns.cpp 836 2007-02-06 15:16:50Z common $ */
 
 #include <sys/poll.h>
-#include <errno.h>
+#include <cstdlib>
+#include <cerrno>
 
 
 #include "dnsresolve-adns.hpp"
