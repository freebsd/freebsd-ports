--- SRC/DEPRECATED/sgeqpf.f.orig	2024-12-03 11:39:11 UTC
+++ SRC/DEPRECATED/sgeqpf.f
@@ -218,8 +218,8 @@
          MA = MIN( ITEMP, M )
          CALL SGEQR2( M, MA, A, LDA, TAU, WORK, INFO )
          IF( MA.LT.N ) THEN
-            CALL SORM2R( 'Left', 'Transpose', M, N-MA, MA, A, LDA, TAU,
-     $                   A( 1, MA+1 ), LDA, WORK, INFO )
+            CALL SORM2R( 'Left', 'Transpose', M, N-MA, MA, A, LDA,
+     $                    TAU, A( 1, MA+1 ), LDA, WORK, INFO )
          END IF
       END IF
 *
