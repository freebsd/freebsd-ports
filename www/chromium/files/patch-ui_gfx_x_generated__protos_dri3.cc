--- ui/gfx/x/generated_protos/dri3.cc.orig	2023-12-10 06:10:27 UTC
+++ ui/gfx/x/generated_protos/dri3.cc
@@ -27,6 +27,8 @@
 #include <xcb/xcb.h>
 #include <xcb/xcbext.h>
 
+#include <unistd.h>
+
 #include "base/logging.h"
 #include "base/posix/eintr_wrapper.h"
 #include "ui/gfx/x/xproto_internal.h"
