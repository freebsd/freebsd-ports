--- SRC/DEPRECATED/zgeqrs.f.orig	2024-12-03 11:39:11 UTC
+++ SRC/DEPRECATED/zgeqrs.f
@@ -15,8 +15,9 @@
 *       INTEGER            INFO, LDA, LDB, LWORK, M, N, NRHS
 *       ..
 *       .. Array Arguments ..
+* Patch from https://github.com/Reference-LAPACK/lapack/pull/1094
 *       COMPLEX*16         A( LDA, * ), B( LDB, * ), TAU( * ),
-*      $                   WORK( LWORK )
+*      $                   WORK( * )
 *       ..
 *
 *
@@ -127,8 +128,9 @@
       INTEGER            INFO, LDA, LDB, LWORK, M, N, NRHS
 *     ..
 *     .. Array Arguments ..
+* Patch from https://github.com/Reference-LAPACK/lapack/pull/1094
       COMPLEX*16         A( LDA, * ), B( LDB, * ), TAU( * ),
-     $                   WORK( LWORK )
+     $                   WORK( * )
 *     ..
 *
 *  =====================================================================
