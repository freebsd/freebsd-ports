-- FreeBSD uses BSD sed which requires an empty string argument for in-place
-- edits ('sed -i "" ...'). The upstream code only handles APPLE (BSD sed)
-- and generic UNIX (GNU sed). Add FreeBSD to the APPLE branch so that the
-- correct BSD sed syntax is used.
--- cmake/external/xxhash.cmake.orig	2026-03-19 06:53:19 UTC
+++ cmake/external/xxhash.cmake
@@ -33,17 +33,26 @@ include_directories(${XXHASH_INCLUDE_DIR})
 
 include_directories(${XXHASH_INCLUDE_DIR})
 
-if(APPLE)
+if(APPLE OR CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+  set(BSD_SED_EMPTY_EXT \"\")
+  if(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+    # FreeBSD uses BSD make which cannot parse xxhash's GNU make Makefile.
+    # Use gmake (GNU make) instead.
+    set(XXHASH_MAKE_CMD gmake)
+  else()
+    set(XXHASH_MAKE_CMD make)
+  endif()
   set(BUILD_CMD
       sed
       -i
-      \"\"
+      ${BSD_SED_EMPTY_EXT}
       "s/-Wstrict-prototypes -Wundef/-Wstrict-prototypes -Wundef -fPIC/g"
       ${SOURCE_DIR}/Makefile
       &&
-      make
+      ${XXHASH_MAKE_CMD}
       lib)
 elseif(UNIX)
+  set(XXHASH_MAKE_CMD make)
   set(BUILD_CMD
       sed
       -i
@@ -99,7 +108,7 @@ else()
     CONFIGURE_COMMAND ""
     BUILD_IN_SOURCE 1
     BUILD_COMMAND ${BUILD_CMD}
-    INSTALL_COMMAND make PREFIX=${XXHASH_INSTALL_DIR} install
+    INSTALL_COMMAND ${XXHASH_MAKE_CMD} PREFIX=${XXHASH_INSTALL_DIR} install
     TEST_COMMAND ""
     BUILD_BYPRODUCTS ${XXHASH_LIBRARIES})
 endif()
