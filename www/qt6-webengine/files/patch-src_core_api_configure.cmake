--- src/core/api/configure.cmake.orig	2023-11-20 16:08:07 UTC
+++ src/core/api/configure.cmake
@@ -10,6 +10,7 @@ if(NOT QT_CONFIGURE_RUNNING)
     if(PkgConfig_FOUND)
         pkg_check_modules(ALSA alsa IMPORTED_TARGET)
         pkg_check_modules(PULSEAUDIO libpulse>=0.9.10 libpulse-mainloop-glib)
+        pkg_check_modules(SNDIO libsndio)
         pkg_check_modules(XDAMAGE xdamage)
         pkg_check_modules(POPPLER_CPP poppler-cpp IMPORTED_TARGET)
         pkg_check_modules(GBM gbm)
@@ -84,6 +85,11 @@ qt_feature("webengine-printing-and-pdf" PRIVATE
     CONDITION TARGET Qt::PrintSupport AND QT_FEATURE_printer AND
     (CUPS_FOUND OR WIN32)
 )
+qt_feature("webengine-system-sndio" PRIVATE
+    LABEL "Use sndio"
+    AUTODETECT UNIX
+    CONDITION SNDIO_FOUND
+)
 qt_feature("webengine-pepper-plugins" PRIVATE
     LABEL "Pepper Plugins"
     PURPOSE "Enables use of Pepper plugins."
@@ -164,7 +170,7 @@ qt_feature("webengine-vaapi" PRIVATE
     PURPOSE "Enables support for VA-API hardware acceleration"
     AUTODETECT GBM_FOUND AND LIBVA_FOUND AND QT_FEATURE_vulkan
     # hardware accelerated encoding requires bundled libvpx
-    CONDITION LINUX AND NOT QT_FEATURE_webengine_system_libvpx
+    CONDITION UNIX AND NOT QT_FEATURE_webengine_system_libvpx
 )
 # internal testing feature
 qt_feature("webengine-system-poppler" PRIVATE
@@ -199,15 +205,19 @@ qt_configure_add_summary_entry(
 )
 qt_configure_add_summary_entry(
     ARGS "webengine-vaapi"
-    CONDITION LINUX
+    CONDITION UNIX
 )
 qt_configure_add_summary_entry(
     ARGS "webengine-system-alsa"
-    CONDITION LINUX
+    CONDITION UNIX
 )
 qt_configure_add_summary_entry(
     ARGS "webengine-system-pulseaudio"
-    CONDITION LINUX
+    CONDITION UNIX
+)
+qt_configure_add_summary_entry(
+    ARGS "webengine-system-sndio"
+    CONDITION UNIX
 )
 qt_configure_add_summary_entry(ARGS "webengine-v8-context-snapshot")
 qt_configure_end_summary_section() # end of "Qt WebEngineCore" section
