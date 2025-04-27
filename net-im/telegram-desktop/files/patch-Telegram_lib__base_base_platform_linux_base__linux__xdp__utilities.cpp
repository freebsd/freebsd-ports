Fix build with Qt >= 6.9.0

Backported from: https://github.com/desktop-app/lib_base/pull/268

--- Telegram/lib_base/base/platform/linux/base_linux_xdp_utilities.cpp.orig	2025-02-25 06:14:47 UTC
+++ Telegram/lib_base/base/platform/linux/base_linux_xdp_utilities.cpp
@@ -16,7 +16,11 @@
 #if QT_VERSION >= QT_VERSION_CHECK(6, 5, 0)
 #include <qpa/qplatformintegration.h>
 #include <private/qguiapplication_p.h>
+#if QT_VERSION >= QT_VERSION_CHECK(6, 9, 0)
+#include <private/qdesktopunixservices_p.h>
+#else // Qt >= 6.9.0
 #include <private/qgenericunixservices_p.h>
+#endif // Qt < 6.9.0
 #endif // Qt >= 6.5.0
 
 #include <sstream>
@@ -39,7 +43,10 @@ std::string ParentWindowID(QWindow *window) {
 	}
 
 #if QT_VERSION >= QT_VERSION_CHECK(6, 5, 0)
-	if (const auto services = dynamic_cast<QGenericUnixServices*>(
+#if QT_VERSION < QT_VERSION_CHECK(6, 9, 0)
+	using QDesktopUnixServices = QGenericUnixServices;
+#endif // Qt < 6.9.0
+	if (const auto services = dynamic_cast<QDesktopUnixServices*>(
 			QGuiApplicationPrivate::platformIntegration()->services())) {
 		return services->portalWindowIdentifier(window).toStdString();
 	}
