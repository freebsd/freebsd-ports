--- style/themeconfig/ThemeConfig.cpp.orig	2019-02-08 18:10:24 UTC
+++ style/themeconfig/ThemeConfig.cpp
@@ -19,7 +19,7 @@
 #include <QFile>
 #include <QApplication>
 #include "ThemeConfig.h"
-#if defined Q_WS_X11 || defined Q_OS_LINUX
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD
 #include <QX11Info>
 #if QT_VERSION >= 0x050000
 #include <X11/Xlib.h>
@@ -37,7 +37,7 @@ ThemeConfig::ThemeConfig(const QString& theme) :
 {
   /* For now, the lack of x11 means wayland.
      Later, a better method should be found. */
-#if defined Q_WS_X11 || defined Q_OS_LINUX
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD
 #if QT_VERSION < 0x050200
   isX11_ = true;
 #else
@@ -544,7 +544,7 @@ theme_spec ThemeConfig::getCompositeSpec()
   default_theme_spec(r);
   QVariant v;
 
-#if defined Q_WS_X11 || defined Q_OS_LINUX
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD
   /* set to false if no compositing manager is running */
 #if QT_VERSION < 0x050200
   if (QX11Info::isCompositingManagerRunning())
