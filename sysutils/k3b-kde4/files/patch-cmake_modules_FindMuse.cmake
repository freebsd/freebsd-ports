--- cmake/modules/FindMuse.cmake.orig	2014-11-04 18:37:31 UTC
+++ cmake/modules/FindMuse.cmake
@@ -15,13 +15,10 @@ if( MUSE_INCLUDE_DIR AND MUSE_LIBRARIES 
 endif( MUSE_INCLUDE_DIR AND MUSE_LIBRARIES )
 
 include(CheckIncludeFiles)
-check_include_files(mpc/mpcdec.h HAVE_MPC_MPCDEC_H)
-check_include_files(mpcdec/mpcdec.h HAVE_MPCDEC_MPCDEC_H)
-check_include_files(musepack/musepack.h HAVE_MUSEPACK_MUSEPACK_H)
+set ( HAVE_MPC_MPCDEC_H 1 )
 
 if( HAVE_MPC_MPCDEC_H )
-    find_path( MUSE_INCLUDE_DIR mpc/mpcdec.h )
-    find_library( MUSE_LIBRARIES NAMES mpcdec )
+    set( MUSE_LIBRARIES mpcdec )
     set( MPC_HEADER_FILE "<mpc/mpcdec.h>" )
 elseif( HAVE_MPCDEC_MPCDEC_H )
     find_path( MUSE_INCLUDE_DIR mpcdec/mpcdec.h )
