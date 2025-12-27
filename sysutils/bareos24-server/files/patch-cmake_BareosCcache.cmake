--- cmake/BareosCcache.cmake	2024-12-31 23:51:38.882883000 -0800
+++ cmake/BareosCcache.cmake	2024-12-31 23:51:48.133339000 -0800
@@ -20,9 +20,6 @@
 find_program(CCACHE_PROGRAM ccache)
 if(CCACHE_PROGRAM)
   set(CCACHE_CMDLINE "${CCACHE_PROGRAM}")
-  list(APPEND CCACHE_CMDLINE "base_dir=${CMAKE_SOURCE_DIR}")
-  list(APPEND CCACHE_CMDLINE "hash_dir=true")
-  list(APPEND CCACHE_CMDLINE "namespace=bareos")
   set(CMAKE_C_COMPILER_LAUNCHER "${CCACHE_CMDLINE}")
   set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE_CMDLINE}")
 endif()
