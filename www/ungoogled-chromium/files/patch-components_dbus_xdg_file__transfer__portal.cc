--- components/dbus/xdg/file_transfer_portal.cc.orig	2026-05-09 18:09:27 UTC
+++ components/dbus/xdg/file_transfer_portal.cc
@@ -31,6 +31,10 @@
 #include "dbus/object_path.h"
 #include "dbus/object_proxy.h"
 
+#if BUILDFLAG(IS_BSD) && !defined(O_PATH)
+#define O_PATH 0
+#endif
+
 namespace dbus_xdg {
 
 BASE_FEATURE(kXdgFileTransferPortal, base::FEATURE_DISABLED_BY_DEFAULT);
