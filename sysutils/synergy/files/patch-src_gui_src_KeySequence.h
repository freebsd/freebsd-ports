Fix build with Qt >= 6.9.0

Backported from: https://github.com/symless/synergy/commit/f48514f57297112f8e1757c11b303dcedbb51644

--- src/gui/src/KeySequence.h.orig	2024-08-30 21:23:08 UTC
+++ src/gui/src/KeySequence.h
@@ -52,6 +52,10 @@ class KeySequence { (private)
   int m_Modifiers;
   bool m_IsValid;
 
+  inline static const int kStrSize = 4;
+  inline static const int kBase = 16;
+  inline static const QChar kFillChar = QChar('0');
+
   static QString keyToString(int key);
 };
 
