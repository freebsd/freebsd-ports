--- cmake/modules/FindMuse.cmake.orig	2014-11-04 18:37:31 UTC
+++ cmake/modules/FindMuse.cmake
@@ -15,9 +15,7 @@ if( MUSE_INCLUDE_DIR AND MUSE_LIBRARIES 
 endif( MUSE_INCLUDE_DIR AND MUSE_LIBRARIES )
 
 include(CheckIncludeFiles)
-check_include_files(mpc/mpcdec.h HAVE_MPC_MPCDEC_H)
-check_include_files(mpcdec/mpcdec.h HAVE_MPCDEC_MPCDEC_H)
-check_include_files(musepack/musepack.h HAVE_MUSEPACK_MUSEPACK_H)
+set ( HAVE_MPC_MPCDEC_H 1 )
 
 if( HAVE_MPC_MPCDEC_H )
     find_path( MUSE_INCLUDE_DIR mpc/mpcdec.h )
