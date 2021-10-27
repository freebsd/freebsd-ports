--- ui/gfx/x/generated_protos/dri3.cc.orig	2021-10-08 06:26:48 UTC
+++ ui/gfx/x/generated_protos/dri3.cc
@@ -43,6 +43,8 @@
 #include <xcb/xcb.h>
 #include <xcb/xcbext.h>
 
+#include <unistd.h>
+
 #include "base/logging.h"
 #include "base/posix/eintr_wrapper.h"
 #include "ui/gfx/x/xproto_internal.h"
