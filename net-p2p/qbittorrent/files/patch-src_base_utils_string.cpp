Avoid use of thread local storage on versions prior to which it was supported.

--- src/base/utils/string.cpp.orig	2016-12-17 18:02:06 UTC
+++ src/base/utils/string.cpp
@@ -37,7 +37,7 @@
 #ifdef QBT_USES_QT5
 #include <QCollator>
 #endif
-#ifdef Q_OS_MAC
+#if defined(Q_OS_MAC) || (defined(__FreeBSD__) && __FreeBSD_version < 1003506)
 #include <QThreadStorage>
 #endif
 
@@ -146,7 +146,8 @@ bool Utils::String::naturalCompareCaseSe
 {
     // provide a single `NaturalCompare` instance for easy use
     // https://doc.qt.io/qt-5/threads-reentrancy.html
-#ifdef Q_OS_MAC  // workaround for Apple xcode: https://stackoverflow.com/a/29929949
+#if defined(Q_OS_MAC) || (defined(__FreeBSD__) && __FreeBSD_version < 1003506)
+// workaround for Apple xcode: https://stackoverflow.com/a/29929949
     static QThreadStorage<NaturalCompare> nCmp;
     if (!nCmp.hasLocalData()) nCmp.setLocalData(NaturalCompare(true));
     return (nCmp.localData())(left, right);
@@ -160,7 +161,8 @@ bool Utils::String::naturalCompareCaseIn
 {
     // provide a single `NaturalCompare` instance for easy use
     // https://doc.qt.io/qt-5/threads-reentrancy.html
-#ifdef Q_OS_MAC  // workaround for Apple xcode: https://stackoverflow.com/a/29929949
+#if defined(Q_OS_MAC) || (defined(__FreeBSD__) && __FreeBSD_version < 1003506)
+// workaround for Apple xcode: https://stackoverflow.com/a/29929949
     static QThreadStorage<NaturalCompare> nCmp;
     if (!nCmp.hasLocalData()) nCmp.setLocalData(NaturalCompare(false));
     return (nCmp.localData())(left, right);
