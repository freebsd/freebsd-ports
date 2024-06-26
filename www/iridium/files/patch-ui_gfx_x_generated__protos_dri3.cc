--- ui/gfx/x/generated_protos/dri3.cc.orig	2024-06-25 12:08:48 UTC
+++ ui/gfx/x/generated_protos/dri3.cc
@@ -27,6 +27,8 @@
 #include <xcb/xcb.h>
 #include <xcb/xcbext.h>
 
+#include <unistd.h>
+
 #include "base/logging.h"
 #include "base/posix/eintr_wrapper.h"
 #include "ui/gfx/x/connection.h"
