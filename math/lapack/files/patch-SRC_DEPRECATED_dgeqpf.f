--- SRC/DEPRECATED/dgeqpf.f.orig	2024-12-03 11:39:11 UTC
+++ SRC/DEPRECATED/dgeqpf.f
@@ -218,8 +218,8 @@
          MA = MIN( ITEMP, M )
          CALL DGEQR2( M, MA, A, LDA, TAU, WORK, INFO )
          IF( MA.LT.N ) THEN
-            CALL DORM2R( 'Left', 'Transpose', M, N-MA, MA, A, LDA, TAU,
-     $                   A( 1, MA+1 ), LDA, WORK, INFO )
+            CALL DORM2R( 'Left', 'Transpose', M, N-MA, MA, A, LDA,
+     $                    TAU, A( 1, MA+1 ), LDA, WORK, INFO )
          END IF
       END IF
 *
