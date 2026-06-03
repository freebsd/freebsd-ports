--- cmake/BareosCcache.cmake	2025-12-04 05:19:30.000000000 -0800
+++ cmake/BareosCcache.cmake	2025-12-17 22:35:19.935427000 -0800
@@ -20,13 +20,6 @@
 find_program(CCACHE_PROGRAM ccache)
 if(CCACHE_PROGRAM)
   set(CCACHE_CMDLINE "${CCACHE_PROGRAM}")
-  list(APPEND CCACHE_CMDLINE "base_dir=${CMAKE_SOURCE_DIR}")
-  if(CCACHE_MAY_HASHDIR)
-    list(APPEND CCACHE_CMDLINE "hash_dir=true")
-  else()
-    list(APPEND CCACHE_CMDLINE "hash_dir=false")
-  endif()
-  list(APPEND CCACHE_CMDLINE "namespace=bareos")
   set(CMAKE_C_COMPILER_LAUNCHER "${CCACHE_CMDLINE}")
   set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE_CMDLINE}")
 endif()
