--- src/core/api/configure.cmake.orig	2022-09-26 10:05:50 UTC
+++ src/core/api/configure.cmake
@@ -7,6 +7,7 @@ if(NOT QT_CONFIGURE_RUNNING)
     if(PkgConfig_FOUND)
         pkg_check_modules(ALSA alsa IMPORTED_TARGET)
         pkg_check_modules(PULSEAUDIO libpulse>=0.9.10 libpulse-mainloop-glib)
+        pkg_check_modules(SNDIO libsndio)
         pkg_check_modules(XDAMAGE xdamage)
         pkg_check_modules(POPPLER_CPP poppler-cpp IMPORTED_TARGET)
         if(NOT GIO_FOUND)
@@ -79,6 +80,11 @@ qt_feature("webengine-printing-and-pdf" PRIVATE
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
@@ -184,6 +190,10 @@ qt_configure_add_summary_entry(
 )
 qt_configure_add_summary_entry(
     ARGS "webengine-system-pulseaudio"
+    CONDITION UNIX
+)
+qt_configure_add_summary_entry(
+    ARGS "webengine-system-sndio"
     CONDITION UNIX
 )
 qt_configure_end_summary_section() # end of "Qt WebEngineCore" section
