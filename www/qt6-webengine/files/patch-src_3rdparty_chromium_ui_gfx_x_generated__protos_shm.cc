--- src/3rdparty/chromium/ui/gfx/x/generated_protos/shm.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/gfx/x/generated_protos/shm.cc
@@ -27,6 +27,8 @@
 #include <xcb/xcb.h>
 #include <xcb/xcbext.h>
 
+#include <unistd.h>
+
 #include "base/logging.h"
 #include "base/posix/eintr_wrapper.h"
 #include "ui/gfx/x/connection.h"
