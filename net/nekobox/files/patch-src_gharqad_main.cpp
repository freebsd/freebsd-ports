-- Suppress unused-value warnings for QT_TRANSLATE_NOOP.
--
--- src/gharqad/main.cpp.orig	2026-06-04 03:57:05 UTC
+++ src/gharqad/main.cpp
@@ -169,25 +169,25 @@ static void loadTranslate(QString locale) {
 }
 
 static void loadTranslate(QString locale) {
-  QT_TRANSLATE_NOOP("QPlatformTheme", "Cancel");
-  QT_TRANSLATE_NOOP("QPlatformTheme", "Apply");
-  QT_TRANSLATE_NOOP("QPlatformTheme", "Yes");
-  QT_TRANSLATE_NOOP("QPlatformTheme", "No");
-  QT_TRANSLATE_NOOP("QPlatformTheme", "OK");
-  QT_TRANSLATE_NOOP("QPlatformTheme", "Defaults");
-  QT_TRANSLATE_NOOP("QPlatformTheme", "Restore Defaults");
-  QT_TRANSLATE_NOOP("QPlatformTheme", "Discard");
+  (void)QT_TRANSLATE_NOOP("QPlatformTheme", "Cancel");
+  (void)QT_TRANSLATE_NOOP("QPlatformTheme", "Apply");
+  (void)QT_TRANSLATE_NOOP("QPlatformTheme", "Yes");
+  (void)QT_TRANSLATE_NOOP("QPlatformTheme", "No");
+  (void)QT_TRANSLATE_NOOP("QPlatformTheme", "OK");
+  (void)QT_TRANSLATE_NOOP("QPlatformTheme", "Defaults");
+  (void)QT_TRANSLATE_NOOP("QPlatformTheme", "Restore Defaults");
+  (void)QT_TRANSLATE_NOOP("QPlatformTheme", "Discard");
 
-  QT_TRANSLATE_NOOP("QPlatformTheme", "Undo");
-  QT_TRANSLATE_NOOP("QPlatformTheme", "Redo");
-  QT_TRANSLATE_NOOP("QPlatformTheme", "Cut");
-  QT_TRANSLATE_NOOP("QPlatformTheme", "Copy");
-  QT_TRANSLATE_NOOP("QPlatformTheme", "Paste");
-  QT_TRANSLATE_NOOP("QPlatformTheme", "Delete");
-  QT_TRANSLATE_NOOP("QPlatformTheme", "Select All");
-  QT_TRANSLATE_NOOP("QPlatformTheme", "Stop");
-  QT_TRANSLATE_NOOP("QPlatformTheme", "Clear");
-  QT_TRANSLATE_NOOP("QPlatformTheme", "Copy Link Location");
+  (void)QT_TRANSLATE_NOOP("QPlatformTheme", "Undo");
+  (void)QT_TRANSLATE_NOOP("QPlatformTheme", "Redo");
+  (void)QT_TRANSLATE_NOOP("QPlatformTheme", "Cut");
+  (void)QT_TRANSLATE_NOOP("QPlatformTheme", "Copy");
+  (void)QT_TRANSLATE_NOOP("QPlatformTheme", "Paste");
+  (void)QT_TRANSLATE_NOOP("QPlatformTheme", "Delete");
+  (void)QT_TRANSLATE_NOOP("QPlatformTheme", "Select All");
+  (void)QT_TRANSLATE_NOOP("QPlatformTheme", "Stop");
+  (void)QT_TRANSLATE_NOOP("QPlatformTheme", "Clear");
+  (void)QT_TRANSLATE_NOOP("QPlatformTheme", "Copy Link Location");
 
   if (trans != nullptr) {
     trans->deleteLater();
