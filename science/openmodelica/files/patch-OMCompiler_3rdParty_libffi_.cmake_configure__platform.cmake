--- OMCompiler/3rdParty/libffi/.cmake/configure_platform.cmake.orig	2025-10-15 12:39:07 UTC
+++ OMCompiler/3rdParty/libffi/.cmake/configure_platform.cmake
@@ -38,6 +38,8 @@ if("${TARGET_PLATFORM}" STREQUAL "")
         else()
             set(TARGET_PLATFORM ARM)
         endif()
+    elseif(HOST_ARCH MATCHES powerpc64.*|ppc64.*)
+        set(TARGET_PLATFORM POWERPC)
     else()
         message(FATAL_ERROR "Unknown host.")
     endif()
