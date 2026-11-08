--- components/dbus/xdg/file_transfer_portal.cc.orig	2026-08-13 07:41:05 UTC
+++ components/dbus/xdg/file_transfer_portal.cc
@@ -32,6 +32,10 @@
 #include "dbus/object_path.h"
 #include "dbus/object_proxy.h"
 
+#if BUILDFLAG(IS_BSD) && !defined(O_PATH)
+#define O_PATH 0
+#endif
+
 namespace dbus_xdg {
 
 BASE_FEATURE(kXdgFileTransferPortal, base::FEATURE_ENABLED_BY_DEFAULT);
