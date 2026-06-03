--- CMakeModules/CompilerFlags.cmake.orig	2025-12-14 16:00:00 UTC
+++ CMakeModules/CompilerFlags.cmake
@@ -23,7 +23,7 @@ enable_if_supported(COMPILER_FLAGS_THIRD_PARTY "/wd426
 enable_if_supported(COMPILER_FLAGS_THIRD_PARTY "/wd4244")
 enable_if_supported(COMPILER_FLAGS_THIRD_PARTY "/wd4267")

-enable_if_links(LINK_FLAGS_RELEASE "-flto")
+#enable_if_links(LINK_FLAGS_RELEASE "-flto")

 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILER_FLAGS}")
 set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMPILER_FLAGS}")
