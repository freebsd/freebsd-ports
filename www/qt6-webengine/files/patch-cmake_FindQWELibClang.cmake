--- cmake/FindQWELibClang.cmake.orig	2026-02-26 14:39:03 UTC
+++ cmake/FindQWELibClang.cmake
@@ -33,7 +33,7 @@ if(Clang_EXECUTABLE)
 
     # Try to find the llvm-config executable, and extract the library location from it
     find_program(QWELibClang_LLVM_CONFIG_EXECUTABLE
-        NAMES llvm-config
+        NAMES llvm-config%%LLVM_VERSION%%
         PATHS ${QWELibClang_BIN_PATH}
         NO_DEFAULT_PATH)
 
