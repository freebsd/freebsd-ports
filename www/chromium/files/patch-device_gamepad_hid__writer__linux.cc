--- device/gamepad/hid_writer_linux.cc.orig	2019-10-31 07:37:06 UTC
+++ device/gamepad/hid_writer_linux.cc
@@ -4,6 +4,8 @@
 
 #include "device/gamepad/hid_writer_linux.h"
 
+#include <unistd.h>
+
 #include "base/posix/eintr_wrapper.h"
 
 namespace device {
