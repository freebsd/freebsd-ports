--- rkward/rbackend/FindR.cmake.orig	2015-01-15 13:37:21 UTC
+++ rkward/rbackend/FindR.cmake
@@ -120,7 +120,7 @@ ELSE(NOT LIBR_LAPACK)
 		# needed when linking to Rlapack on linux for some unknown reason.
 		# apparently not needed on windows (let's see, when it comes back to bite us, though)
 		# and compiling on windows is hard enough even without requiring libgfortran, too.
-		SET(R_USED_LIBS ${R_USED_LIBS} gfortran)
+		#SET(R_USED_LIBS ${R_USED_LIBS} gfortran)
 	ENDIF(WIN32 OR APPLE)
 ENDIF(NOT LIBR_LAPACK)
 
