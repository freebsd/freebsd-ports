--- src/core/api/configure.cmake.orig	2025-08-18 00:53:11 UTC
+++ src/core/api/configure.cmake
@@ -10,6 +10,7 @@ if(NOT QT_CONFIGURE_RUNNING)
     if(PkgConfig_FOUND AND QT_FEATURE_pkg_config)
         pkg_check_modules(ALSA alsa IMPORTED_TARGET)
         pkg_check_modules(PULSEAUDIO libpulse>=0.9.10 libpulse-mainloop-glib)
+        pkg_check_modules(SNDIO libsndio)
         pkg_check_modules(XDAMAGE xdamage)
         pkg_check_modules(GBM gbm)
         pkg_check_modules(LIBVA libva>=1.14)
@@ -90,6 +91,11 @@ qt_feature("webengine-printing-and-pdf" PRIVATE
     AUTODETECT NOT QT_FEATURE_webengine_embedded_build
     CONDITION TARGET Qt::PrintSupport AND QT_FEATURE_printer
 )
+qt_feature("webengine-system-sndio" PRIVATE
+    LABEL "Use sndio"
+    AUTODETECT UNIX
+    CONDITION SNDIO_FOUND
+)
 qt_feature("webengine-pepper-plugins" PRIVATE
     LABEL "Pepper Plugins"
     PURPOSE "Enables use of Pepper plugins."
@@ -171,7 +177,7 @@ qt_feature("webengine-vaapi" PRIVATE
     PURPOSE "Enables support for VA-API hardware acceleration"
     AUTODETECT GBM_FOUND AND LIBVA_FOUND AND QT_FEATURE_vulkan
     # hardware accelerated encoding requires bundled libvpx
-    CONDITION LINUX AND NOT QT_FEATURE_webengine_system_libvpx
+    CONDITION UNIX AND NOT QT_FEATURE_webengine_system_libvpx
 )
 list(LENGTH CMAKE_OSX_ARCHITECTURES osx_arch_count)
 qt_feature("webenginedriver" PUBLIC
@@ -214,15 +220,19 @@ qt_configure_add_summary_entry(
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
 qt_configure_add_summary_entry(ARGS "webenginedriver")
