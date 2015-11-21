--- rkward/rbackend/FindR.cmake.orig	2011-02-23 06:43:20.000000000 -0500
+++ rkward/rbackend/FindR.cmake	2011-05-03 01:42:49.000000000 -0400
@@ -99,7 +99,7 @@
 		# needed when linking to Rlapack on linux for some unknown reason.
 		# apparently not needed on windows (let's see, when it comes back to bite us, though)
 		# and compiling on windows is hard enough even without requiring libgfortran, too.
-		SET(R_USED_LIBS ${R_USED_LIBS} gfortran)
+		#SET(R_USED_LIBS ${R_USED_LIBS} gfortran)
 	ENDIF(WIN32 OR APPLE)
 ENDIF(NOT LIBR_LAPACK)
 
