# Avoid use of thread local storage on versions prior to which it was supported.
#
# Qt::escape is part of QtGui, upstream patch replaces it for webui
#
--- src/base/utils/string.cpp.orig	2017-03-03 23:20:21 UTC
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
@@ -217,6 +219,23 @@ QString Utils::String::toHtmlEscaped(con
 #ifdef QBT_USES_QT5
     return str.toHtmlEscaped();
 #else
-    return Qt::escape(str);
+    // code from Qt
+    QString rich;
+    const int len = str.length();
+    rich.reserve(int(len * 1.1));
+    for (int i = 0; i < len; ++i) {
+        if (str.at(i) == QLatin1Char('<'))
+            rich += QLatin1String("&lt;");
+        else if (str.at(i) == QLatin1Char('>'))
+            rich += QLatin1String("&gt;");
+        else if (str.at(i) == QLatin1Char('&'))
+            rich += QLatin1String("&amp;");
+        else if (str.at(i) == QLatin1Char('"'))
+            rich += QLatin1String("&quot;");
+        else
+            rich += str.at(i);
+    }
+    rich.squeeze();
+    return rich;
 #endif
 }
