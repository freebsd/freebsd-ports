--- config/fmt.cmake.orig	2024-04-07 21:30:28 UTC
+++ config/fmt.cmake
@@ -23,7 +23,7 @@ endif()
 endif()
 
 # Try in three passes, otherwise cmake gets in the way...
-find_path   (FMT_INCDIR fmt/core.h HINTS ${FMT_INCDIR_HINTS} DOC "fmt headers"
+find_path   (FMT_INCDIR fmt-invalid/core.h HINTS ${FMT_INCDIR_HINTS} DOC "fmt headers"
         NO_DEFAULT_PATH
         NO_SYSTEM_ENVIRONMENT_PATH
         NO_CMAKE_PATH
@@ -32,19 +32,19 @@ if(NOT FMT_INCDIR)
         NO_CMAKE_FIND_ROOT_PATH
         )
 if(NOT FMT_INCDIR)
-find_path   (FMT_INCDIR fmt/core.h HINTS ${FMT_INCDIR_HINTS} DOC "fmt headers"
+find_path   (FMT_INCDIR fmt-invalid/core.h HINTS ${FMT_INCDIR_HINTS} DOC "fmt headers"
         NO_DEFAULT_PATH
         )
 endif()
 if(NOT FMT_INCDIR)
-find_path   (FMT_INCDIR fmt/core.h HINTS ${FMT_INCDIR_HINTS} DOC "fmt headers")
+find_path   (FMT_INCDIR fmt-invalid/core.h HINTS ${FMT_INCDIR_HINTS} DOC "fmt headers")
 endif()
 
-find_library(FMT_LIB    fmt   HINTS ${FMT_LIBDIR_HINTS} DOC "fmt library"
+find_library(FMT_LIB    fmt-invalid   HINTS ${FMT_LIBDIR_HINTS} DOC "fmt library"
     NO_DEFAULT_PATH
     )
 if(NOT FMT_LIB)
-find_library(FMT_LIB    fmt   HINTS ${FMT_LIBDIR_HINTS} DOC "fmt library")
+find_library(FMT_LIB    fmt-invalid   HINTS ${FMT_LIBDIR_HINTS} DOC "fmt library")
 endif()
 
 
