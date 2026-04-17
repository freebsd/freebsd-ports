Hunk 1: Adapt for Qt 6.10.0. The private QPA header genericunixthemes_p.h was
renamed to qgenericunixtheme_p.h.

Hunk 2: Adapt for Qt 6.10.3. The OffscreenSurface class is shadowed by the
inherited OffscreenSurface enumerator defined in
${LOCALBASE}/include/qt6/QtGui/${QT6_VERSION}/QtGui/qpa/qplatformintegration.h
after [1].

[1] https://code.qt.io/cgit/qt/qtbase.git/commit/?id=31819fe28ef9a54097cc0ca4e892f20abc131675

--- plugins/qpa/integration.cpp.orig	2024-10-09 12:19:16 UTC
+++ plugins/qpa/integration.cpp
@@ -25,9 +25,14 @@ SPDX-License-Identifier: GPL-2.0-or-later
 #include <qpa/qwindowsysteminterface.h>
 
 #include <QtGui/private/qgenericunixfontdatabase_p.h>
-#include <QtGui/private/qgenericunixthemes_p.h>
 #include <QtGui/private/qunixeventdispatcher_qpa_p.h>
 
+#if QT_VERSION >= QT_VERSION_CHECK(6,10,0)
+#include <QtGui/private/qgenericunixtheme_p.h>
+#else
+#include <QtGui/private/qgenericunixthemes_p.h>
+#endif
+
 #if !defined(QT_NO_ACCESSIBILITY_ATSPI_BRIDGE)
 #include <QtGui/private/qspiaccessiblebridge_p.h>
 #endif
@@ -117,7 +122,7 @@ Integration::createPlatformOffscreenSurface(QOffscreen
 QPlatformOffscreenSurface*
 Integration::createPlatformOffscreenSurface(QOffscreenSurface* surface) const
 {
-    return new OffscreenSurface(surface);
+    return new como::QPA::OffscreenSurface(surface);
 }
 
 QPlatformFontDatabase* Integration::fontDatabase() const
