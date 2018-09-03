--- cmake/tests/test_Wannier90.cmake.orig	2018-07-03 14:37:33 UTC
+++ cmake/tests/test_Wannier90.cmake
@@ -1,12 +1,12 @@
 #first try if Wannier90 already works
 try_compile(FLEUR_USE_WANN ${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR}/cmake/tests/test_Wannier90.f90
-	    LINK_LIBRARIES ${FLEUR_LIBRARIES}
+	    LINK_LIBRARIES ${FLEUR_LIBRARIES} -lwannier
             )
 
 message("Wannier90 1.2 Library found:${FLEUR_USE_WANN}")
 
 if (DEFINED ENV{FLEUR_USE_WANNIER})
-   if (ENV{FLEUR_USE_WANNIER})
+   if ($ENV{FLEUR_USE_WANNIER})
        if (NOT FLEUR_USE_WANN)
            message(FATAL_ERROR "You asked for Wannier90 but cmake couldn't find it. Please check your Fortran compiler settings")
        endif()
