--- SRC/DEPRECATED/cgeqrs.f.orig	2024-12-03 11:39:11 UTC
+++ SRC/DEPRECATED/cgeqrs.f
@@ -15,8 +15,9 @@
 *       INTEGER            INFO, LDA, LDB, LWORK, M, N, NRHS
 *       ..
 *       .. Array Arguments ..
+* Patch from https://github.com/Reference-LAPACK/lapack/pull/1094
 *       COMPLEX            A( LDA, * ), B( LDB, * ), TAU( * ),
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
       COMPLEX            A( LDA, * ), B( LDB, * ), TAU( * ),
-     $                   WORK( LWORK )
+     $                   WORK( * )
 *     ..
 *
 *  =====================================================================
