--- src/3rdparty/chromium/device/gamepad/hid_writer_linux.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/device/gamepad/hid_writer_linux.cc
@@ -2,6 +2,8 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#include <unistd.h>
+
 #include "device/gamepad/hid_writer_linux.h"
 
 #include <unistd.h>
