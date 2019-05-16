--- tools/cmake/Documentation.cmake.orig	2019-05-16 09:00:44 UTC
+++ tools/cmake/Documentation.cmake
@@ -137,4 +137,4 @@ install(FILES
   ${CMAKE_HOME_DIRECTORY}/docs/manpages/smpif90.1
   ${CMAKE_HOME_DIRECTORY}/docs/manpages/smpiff.1
   ${CMAKE_HOME_DIRECTORY}/docs/manpages/smpirun.1
-  DESTINATION $ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/man/man1)
+  DESTINATION $ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/man/man1)
