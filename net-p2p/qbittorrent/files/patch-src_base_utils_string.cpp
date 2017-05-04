# Avoid use of thread local storage on versions prior to which it was supported.
#
--- src/base/utils/string.cpp.orig	2017-04-06 16:53:25 UTC
+++ src/base/utils/string.cpp
@@ -38,7 +38,7 @@
 #ifdef QBT_USES_QT5
 #include <QCollator>
 #endif
-#ifdef Q_OS_MAC
+#if defined(Q_OS_MAC) || (defined(__FreeBSD__) && __FreeBSD_version < 1003506)
 #include <QThreadStorage>
 #endif
 
@@ -147,7 +147,8 @@ bool Utils::String::naturalCompareCaseSe
 {
     // provide a single `NaturalCompare` instance for easy use
     // https://doc.qt.io/qt-5/threads-reentrancy.html
-#ifdef Q_OS_MAC  // workaround for Apple xcode: https://stackoverflow.com/a/29929949
+#if defined(Q_OS_MAC) || (defined(__FreeBSD__) && __FreeBSD_version < 1003506)
+// workaround for Apple xcode: https://stackoverflow.com/a/29929949
     static QThreadStorage<NaturalCompare> nCmp;
     if (!nCmp.hasLocalData()) nCmp.setLocalData(NaturalCompare(true));
     return (nCmp.localData())(left, right);
@@ -161,7 +162,8 @@ bool Utils::String::naturalCompareCaseIn
 {
     // provide a single `NaturalCompare` instance for easy use
     // https://doc.qt.io/qt-5/threads-reentrancy.html
-#ifdef Q_OS_MAC  // workaround for Apple xcode: https://stackoverflow.com/a/29929949
+#if defined(Q_OS_MAC) || (defined(__FreeBSD__) && __FreeBSD_version < 1003506)
+// workaround for Apple xcode: https://stackoverflow.com/a/29929949
     static QThreadStorage<NaturalCompare> nCmp;
     if (!nCmp.hasLocalData()) nCmp.setLocalData(NaturalCompare(false));
     return (nCmp.localData())(left, right);
