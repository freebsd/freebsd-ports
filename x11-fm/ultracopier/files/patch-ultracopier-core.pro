--- ultracopier-core.pro.orig	2015-04-14 21:52:19 UTC
+++ ultracopier-core.pro
@@ -21,6 +21,10 @@ TRANSLATIONS += plugins/Languages/ar/tra
     plugins/Languages/tr/translation.ts \
     plugins/Languages/zh/translation.ts
 
+for (ts, TRANSLATIONS) {
+    system($$LRELEASE $$ts)
+}
+
 TARGET = ultracopier
 macx {
     ICON = resources/ultracopier.icns
