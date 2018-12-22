--- avahi-qt/qt-watch.cpp.orig	2017-07-10 12:14:59.119370306 +0200
+++ avahi-qt/qt-watch.cpp	2018-12-22 20:56:34.850048000 +0100
@@ -18,10 +18,10 @@
 ***/
 
 #include <sys/time.h>
-#ifdef QT4
-#include <Qt/qsocketnotifier.h>
-#include <Qt/qobject.h>
-#include <Qt/qtimer.h>
+#if defined(QT5) || defined(QT4)
+#include <QSocketNotifier>
+#include <QObject>
+#include <QTimer>
 #else
 #include <qsocketnotifier.h>
 #include <qobject.h>
@@ -114,7 +114,7 @@
     m_callback(callback), m_userdata(userdata)
 {
     connect(&m_timer, SIGNAL(timeout()), this, SLOT(timeout()));
-#ifdef QT4
+#if defined(QT5) || defined(QT4)
     m_timer.setSingleShot(true);
 #endif
     update(tv);
@@ -125,7 +125,7 @@
     m_timer.stop();
     if (tv) {
     AvahiUsec u = avahi_age(tv)/1000;
-#ifdef QT4
+#if defined(QT5) || defined(QT4)
     m_timer.start( (u>0) ? 0 : -u);
 #else
     m_timer.start( (u>0) ? 0 : -u,true);
@@ -191,8 +191,10 @@
     return &qt_poll;
 }
 
-#ifdef QT4
+#if defined(QT5)
+#include "qt-watch.moc5"
+#elif defined(QT4)
 #include "qt-watch.moc4"
-#else
+#elif defined(QT3)
 #include "qt-watch.moc3"
 #endif
