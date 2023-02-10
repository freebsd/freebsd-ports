Index: Source/cmake/WebKitCompilerFlags.cmake
--- Source/cmake/WebKitCompilerFlags.cmake.orig
+++ Source/cmake/WebKitCompilerFlags.cmake
@@ -252,9 +252,9 @@ if (NOT MSVC)
     string(REGEX MATCHALL "-fsanitize=[^ ]*" ENABLED_COMPILER_SANITIZERS ${CMAKE_CXX_FLAGS})
 endif ()
 
-if (UNIX AND NOT APPLE AND NOT ENABLED_COMPILER_SANITIZERS)
-    set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined ${CMAKE_SHARED_LINKER_FLAGS}")
-endif ()
+#if (UNIX AND NOT APPLE AND NOT ENABLED_COMPILER_SANITIZERS)
+#    set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined ${CMAKE_SHARED_LINKER_FLAGS}")
+#endif ()
 
 
 if (MSVC)
