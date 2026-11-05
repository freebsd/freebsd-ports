--- cmake/FindMumps.cmake.orig	2026-10-22 21:06:55 UTC
+++ cmake/FindMumps.cmake
@@ -49,7 +49,7 @@ find_file (MUMPS_SHARED_LIBRARIES
 find_file (MUMPS_SHARED_LIBRARIES
           "lib${MUMPS_ARITH_PREFIX}mumps${CMAKE_SHARED_LIBRARY_SUFFIX}"
           PATHS ${MUMPS_ROOT}
-	      PATH_SUFFIXES "bin"
+	      PATH_SUFFIXES "lib"
          )
 
 find_path(MUMPS_ONLY_INCLUDE_DIRS
@@ -173,4 +173,4 @@ if(MUMPS_FOUND)
 	MARK_AS_ADVANCED(FORCE MUMPS_ROOT)
 	MARK_AS_ADVANCED(FORCE MUMPS_USE_MPI)
 	MARK_AS_ADVANCED(FORCE MUMPS_USE_DEFAULT_ORDERINGS)
-endif()
\ No newline at end of file
+endif()
