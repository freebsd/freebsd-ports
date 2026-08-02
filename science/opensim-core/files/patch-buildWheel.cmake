--- buildWheel.cmake.orig	2026-06-18 22:26:24 UTC
+++ buildWheel.cmake
@@ -22,6 +22,6 @@ else()
     # add $ORIGIN to rpath as layout has changed
     file(GLOB SIMTK_LIBS "${CMAKE_INSTALL_PREFIX}/${OPENSIM_INSTALL_PYTHONDIR}/opensim/libSimTK*.so*")
     foreach(slib ${SIMTK_LIBS})
-        execute_process(COMMAND bash "-c" "patchelf --force-rpath --set-rpath '$ORIGIN' '${slib}'")
+        #execute_process(COMMAND bash "-c" "patchelf --force-rpath --set-rpath '$ORIGIN' '${slib}'")
     endforeach()
 endif()
