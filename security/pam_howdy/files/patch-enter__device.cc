--- enter_device.cc.orig	2023-03-08 16:41:32 UTC
+++ enter_device.cc
@@ -3,6 +3,7 @@
 #include <cstring>
 #include <memory>
 #include <stdexcept>
+#include <string>
 
 EnterDevice::EnterDevice()
     : raw_device(libevdev_new(), &libevdev_free),
