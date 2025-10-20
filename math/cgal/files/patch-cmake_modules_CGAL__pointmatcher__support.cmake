--- cmake/modules/CGAL_pointmatcher_support.cmake.orig	2024-08-10 19:00:05 UTC
+++ cmake/modules/CGAL_pointmatcher_support.cmake
@@ -1,9 +1,8 @@ if(libpointmatcher_FOUND AND NOT TARGET CGAL::pointmat
 if(libpointmatcher_FOUND AND NOT TARGET CGAL::pointmatcher_support)
-  find_package(Boost COMPONENTS thread filesystem system program_options date_time chrono)
+  find_package(Boost COMPONENTS thread filesystem program_options date_time chrono)
   if(Boost_chrono_FOUND
       AND Boost_thread_FOUND
       AND Boost_filesystem_FOUND
-      AND Boost_system_FOUND
       AND Boost_program_options_FOUND
       AND Boost_date_time_FOUND)
     add_library(CGAL::pointmatcher_support INTERFACE IMPORTED)
@@ -11,6 +10,6 @@ if(libpointmatcher_FOUND AND NOT TARGET CGAL::pointmat
     target_include_directories(CGAL::pointmatcher_support INTERFACE "${libpointmatcher_INCLUDE_DIR}")
     target_link_libraries(CGAL::pointmatcher_support INTERFACE ${libpointmatcher_LIBRARIES} libnabo::nabo)
   else()
-    message(STATUS "NOTICE: the libpointmatcher library requires the following boost components: thread filesystem system program_options date_time chrono.")
+    message(STATUS "NOTICE: the libpointmatcher library requires the following boost components: thread filesystem program_options date_time chrono.")
   endif()
 endif()
