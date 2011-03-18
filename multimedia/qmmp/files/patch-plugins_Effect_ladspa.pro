--- src/plugins/Effect/ladspa/ladspa.pro.orig	2010-01-26 05:36:55.000000000 +0900
+++ src/plugins/Effect/ladspa/ladspa.pro	2010-05-07 19:43:53.000000000 +0900
@@ -23,8 +23,7 @@
 QMAKE_LIBDIR += ../../../../lib
 LIBS += -lqmmp \
     -L/usr/lib \
-    -I/usr/include \
-    -ldl
+    -I/usr/include
 TRANSLATIONS = translations/ladspa_plugin_cs.ts \
     translations/ladspa_plugin_de.ts \
     translations/ladspa_plugin_zh_CN.ts \
