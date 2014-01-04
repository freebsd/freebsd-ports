--- ./src/frontend/settingsdialogs/bttextfilterstab.cpp.orig	2013-12-24 05:36:03.000000000 -0500
+++ ./src/frontend/settingsdialogs/bttextfilterstab.cpp	2014-01-04 02:20:11.000000000 -0500
@@ -52,7 +52,7 @@
 }
 
 #define TEXT_FILTERS_TAB_SAVE(name) \
-    btConfig().setValue(#name, m_ ## name ## Check->isChecked())
+    btConfig().setSessionValue(#name, m_ ## name ## Check->isChecked())
 
 void BtTextFiltersTab::save() {
     btConfig().beginGroup("presentation");
