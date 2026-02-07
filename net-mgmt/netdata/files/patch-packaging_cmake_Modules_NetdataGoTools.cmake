--- packaging/cmake/Modules/NetdataGoTools.cmake.orig	2025-05-28 22:57:38 UTC
+++ packaging/cmake/Modules/NetdataGoTools.cmake
@@ -30,7 +30,7 @@ macro(add_go_target target output build_src build_dir)
 
     add_custom_command(
         OUTPUT ${output}
-        COMMAND "${CMAKE_COMMAND}" -E env GOROOT=${GO_ROOT} CGO_ENABLED=0 GOPROXY=https://proxy.golang.org,direct "${GO_EXECUTABLE}" build -buildvcs=false -ldflags "${GO_LDFLAGS}" -o "${CMAKE_BINARY_DIR}/${output}" "./${build_dir}"
+        COMMAND "${CMAKE_COMMAND}" -E env GOROOT=${GO_ROOT} CGO_ENABLED=0 GOPROXY=off "${GO_EXECUTABLE}" build -buildvcs=false -mod=vendor -ldflags "${GO_LDFLAGS}" -o "${CMAKE_BINARY_DIR}/${output}" "./${build_dir}"
         DEPENDS ${${target}_DEPS}
         COMMENT "Building Go component ${output}"
         WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/${build_src}"
