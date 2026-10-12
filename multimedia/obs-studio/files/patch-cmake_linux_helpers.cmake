--- cmake/linux/helpers.cmake.orig	2026-08-14 22:07:04 UTC
+++ cmake/linux/helpers.cmake
@@ -161,7 +161,7 @@ function(set_target_properties_obs targe
       )
     elseif(${target} STREQUAL obs-browser)
       message(DEBUG "Add Chromium Embedded Framework to project for obs-browser plugin...")
-      if(TARGET CEF::Library)
+      if(TARGET CEF::Library AND NOT OS_FREEBSD)
         get_target_property(imported_location CEF::Library IMPORTED_LOCATION_RELEASE)
 
         if(imported_location)
