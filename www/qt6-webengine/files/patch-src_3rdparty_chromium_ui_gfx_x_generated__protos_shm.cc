--- src/3rdparty/chromium/ui/gfx/x/generated_protos/shm.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/gfx/x/generated_protos/shm.cc
@@ -44,6 +44,8 @@
 #include <xcb/xcb.h>
 #include <xcb/xcbext.h>
 
+#include <unistd.h>
+
 #include "base/logging.h"
 #include "base/posix/eintr_wrapper.h"
 #include "ui/gfx/x/xproto_internal.h"
