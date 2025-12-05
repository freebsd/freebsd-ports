Adapt for Qt 6.10.0. The private QPA header genericunixthemes_p.h was
renamed to qgenericunixtheme_p.h.

--- plugins/qpa/integration.cpp.orig	2024-10-09 12:19:16 UTC
+++ plugins/qpa/integration.cpp
@@ -25,8 +25,13 @@ SPDX-License-Identifier: GPL-2.0-or-later
 #include <qpa/qwindowsysteminterface.h>
 
 #include <QtGui/private/qgenericunixfontdatabase_p.h>
-#include <QtGui/private/qgenericunixthemes_p.h>
 #include <QtGui/private/qunixeventdispatcher_qpa_p.h>
+
+#if QT_VERSION >= QT_VERSION_CHECK(6,10,0)
+#include <QtGui/private/qgenericunixtheme_p.h>
+#else
+#include <QtGui/private/qgenericunixthemes_p.h>
+#endif
 
 #if !defined(QT_NO_ACCESSIBILITY_ATSPI_BRIDGE)
 #include <QtGui/private/qspiaccessiblebridge_p.h>
