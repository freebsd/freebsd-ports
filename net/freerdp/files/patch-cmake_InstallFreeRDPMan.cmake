--- cmake/InstallFreeRDPMan.cmake.orig	2023-12-14 18:03:49 UTC
+++ cmake/InstallFreeRDPMan.cmake
@@ -1,6 +1,6 @@
 function(install_freerdp_man manpage section)
  if(WITH_MANPAGES)
-   if(OPENBSD OR FREEBSD)
+   if(OPENBSD)
        install(FILES ${manpage} DESTINATION man/man${section})
     else()
        install(FILES ${manpage} DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/man/man${section})
