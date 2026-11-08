--- cmake/tests/test_Wannier90.cmake.orig	2026-04-28 12:13:48 UTC
+++ cmake/tests/test_Wannier90.cmake
@@ -1,9 +1,10 @@
 #first try if Wannier90 already works
+if (FALSE) # disable search for wannier90 library because latest version isn't compatible with FLEUR
 try_compile(FLEUR_USE_WANN ${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR}/cmake/tests/test_Wannier90.f90
 	    LINK_LIBRARIES ${FLEUR_LIBRARIES}
             )
 set(FLEUR_WANNIER90_LIBRARIES ${FLEUR_LIBRARIES}) 
-foreach(ADD_String "-lwannier" )
+foreach(ADD_String "-lwannier90" )
    if (NOT FLEUR_USE_WANN)
      set(TEST_LIBRARIES "${ADD_String};${FLEUR_LIBRARIES}")
 
@@ -21,6 +22,7 @@ message("Wannier90 1.2 Library found:${FLEUR_USE_WANN}
 endforeach()
 
 message("Wannier90 1.2 Library found:${FLEUR_USE_WANN}")
+endif() # disable search for wannier90 library because latest version isn't compatible with FLEUR
 
 if (DEFINED CLI_FLEUR_USE_WANNIER)
    if (CLI_FLEUR_USE_WANNIER)
