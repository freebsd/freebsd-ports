Fix build with Qt >= 6.9.0

Backported from: https://github.com/symless/synergy/commit/f48514f57297112f8e1757c11b303dcedbb51644

--- src/gui/src/KeySequence.cpp.orig	2024-08-30 21:23:08 UTC
+++ src/gui/src/KeySequence.cpp
@@ -207,9 +207,14 @@ QString KeySequence::keyToString(int key) {
   }
 
   // representable in ucs2?
-  if (key < 0x10000)
-    return QString("\\u%1").arg(
-        QChar(key).toLower().unicode(), 4, 16, QChar('0'));
+  if (key < 0x10000) {
+#if QT_VERSION >= QT_VERSION_CHECK(6, 9, 0)
+    const uint16_t keyHex = QChar(key).toLower().unicode();
+    return QString("\\u%1").arg(keyHex, kStrSize, kBase, kFillChar);
+#else
+    return QString("\\u%1").arg(QChar(key).toLower().unicode(), kStrSize, kBase, kFillChar);
+#endif
+  }
 
   // give up, synergy probably won't handle this
   return "";
