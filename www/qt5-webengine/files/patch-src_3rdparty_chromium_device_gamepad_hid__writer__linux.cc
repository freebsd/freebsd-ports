--- src/3rdparty/chromium/device/gamepad/hid_writer_linux.cc.orig	2020-03-16 14:04:24 UTC
+++ src/3rdparty/chromium/device/gamepad/hid_writer_linux.cc
@@ -4,6 +4,8 @@
 
 #include "device/gamepad/hid_writer_linux.h"
 
+#include <unistd.h>
+
 #include "base/posix/eintr_wrapper.h"
 
 namespace device {
